
#include <string.h>
#include <stdlib.h>
// #include <time.h>
#include "Hash Table.h"

UINT32 indexer(hashTable* pht,void* pkey, size_t sizeKey){
    return hashInts(MurmurHash64A(pkey,sizeKey,5),pht->m,pht->A,pht->B);
}
UINT8 findCollisionNodeByKey(hashTable* pht, void* pkey, size_t sizeKey,node** ppNode){
    UINT32 index = indexer(pht,pkey,sizeKey);
    INT8* unit=(INT8*)pkey;
    node* nody=pht->slots[index].items.head;
    for (int i = 0; i < len(&(pht->slots[index].items)) ; i++)
    {
        if (sizeKey==((item*)(nody->value))->keySize)
        {
            INT8* keyy=((item*)(nody->value))->key;
            for (size_t j = 0; j < sizeKey; j++)
            {
               if (unit[j]!=keyy[j]) break;
               if (j==sizeKey-1) {
                    *ppNode=nody;
                    return 1;
               }
            }
        }
        nody=nody->next;
    }
    *ppNode=NULL;
    return 0;
}
UINT32 getIndexByKey(hashTable* pht, void * pkey, size_t sizeKey){
    return indexer(pht,pkey,sizeKey);
}



UINT8 createHashTable(hashTable* pht, UINT32 m){
    pht->slots=(slot*)malloc(m*sizeof(slot));
    intializeDoublyLinkedList(&(pht->keys));
    for (size_t i = 0; i < m; i++)
    {
        intializeDoublyLinkedList(&((pht->slots)[i].items));
    }
    pht->m=m;
    pht->size=0;
    //srand((unsigned int)time(NULL));
    //label:
    //pht->A=rand();
    //pht->B=rand();
    //if (pht->A%2==0) goto label;
    pht->A=1;
    pht->B=0;
    return 1;
}
UINT8 insertKeyValuePair(hashTable* pht, void* pkey, size_t sizeKey, void* pvalue, size_t sizeValue, char* typeDes, size_t typeDesSize){
    node* tempnode;
    BOOL keyExist = findCollisionNodeByKey(pht,pkey,sizeKey,&tempnode);
    if ( keyExist)
    {
        item existingItem = *((item*)tempnode->value);
        free(existingItem.key);
        free(existingItem.value);
        free(existingItem.typeDescription);
        void* keycopy=malloc(sizeKey);
        void* valuecopy=malloc(sizeValue);
        void* typedescopy=malloc(typeDesSize);

        memcpy(keycopy,pkey,sizeKey);
        memcpy(valuecopy,pvalue,sizeValue);
        memcpy(typedescopy,typeDes,typeDesSize);

        existingItem.key=keycopy;
        existingItem.value=valuecopy;
        existingItem.keySize=sizeKey;
        existingItem.valueSize=sizeValue;
        existingItem.typeDescription=typedescopy;
        existingItem.typeDescriptionSize=typeDesSize;
        return 1;
    }
    else if (!keyExist){
         UINT32 index = indexer(pht,pkey,sizeKey);
         item* pcollisionListItem=(item*)malloc(sizeof(item));
         void* keycopy=malloc(sizeKey);
         void* valuecopy=malloc(sizeValue);
         void* typedescopy=malloc(typeDesSize);

         memcpy(keycopy,pkey,sizeKey);
         memcpy(valuecopy,pvalue,sizeValue);
         memcpy(typedescopy,typeDes,typeDesSize);

         pcollisionListItem->key=keycopy;
         pcollisionListItem->value=valuecopy;
         pcollisionListItem->keySize=sizeKey;
         pcollisionListItem->valueSize=sizeValue;
         pcollisionListItem->typeDescription=typedescopy;
         pcollisionListItem->typeDescriptionSize=typeDesSize;

         node* pCollisionListNode;
         //allocNode(pCollisionListNode);
          pCollisionListNode = (node*)malloc(sizeof(node));
          pCollisionListNode->next=pCollisionListNode->prev=pCollisionListNode->value=NULL;
         insertLast(&(pht->slots[index].items),pCollisionListNode);

         node* pKeyListNode;
         //allocNode(pKeyListNode);
          pKeyListNode = (node*)malloc(sizeof(node));
          pKeyListNode->next=pKeyListNode->prev=pKeyListNode->value=NULL;
         insertLast(&(pht->keys),pKeyListNode);

         pCollisionListNode->value=pcollisionListItem;
         pKeyListNode->value=pcollisionListItem;

         pcollisionListItem->pColisionListNode=pCollisionListNode;
         pcollisionListItem->pKeyListNode=pKeyListNode;

         pht->size++;
         return 1;
    }
    else return 0;
}
UINT8 removeKey(hashTable* pht, void* pkey, size_t sizeKey){
    UINT32 index = indexer(pht,pkey,sizeKey);
    node* pCollisionListNode;
    if(findCollisionNodeByKey(pht,pkey,sizeKey,&pCollisionListNode)){
        item* pCollisionListItem = pCollisionListNode->value;

        free( pCollisionListItem->key);
        free( pCollisionListItem->value);
        free( pCollisionListItem->typeDescription);

        node* pKeyListNode = pCollisionListItem->pKeyListNode;
        free(&pCollisionListNode->value);
        deleteNode(&(pht->keys),pKeyListNode);
        deleteNode(&(pht->slots[index].items),pCollisionListNode);

        pht->size--;
        return 1;
    }
    else return 0; 

}
void getValue(hashTable* pht, void* pkey, size_t sizeKey, void** pvalue, size_t *sizeValue,char** pTypeDes, size_t *typeDesSize){
        node* pCollisionListNode;
        findCollisionNodeByKey(pht,pkey,sizeKey,&pCollisionListNode);
        item* pCollisionListItem = pCollisionListNode->value;
        *pvalue=pCollisionListItem->value;
        *pTypeDes=pCollisionListItem->typeDescription;
        *sizeValue=pCollisionListItem->valueSize;
        *typeDesSize=pCollisionListItem->typeDescriptionSize;

//         node* pCollisionListNode;
//         findCollisionNodeByKey(pht,pkey,sizeKey,&pCollisionListNode);
//         item* pCollisionListItem = pCollisionListNode->value;
//         pvalue=malloc(pCollisionListItem->valueSize);
//         pTypeDes=malloc(pCollisionListItem->typeDescriptionSize);
//         memcpy(pvalue,pCollisionListItem->value,pCollisionListItem->valueSize);
//         memcpy(pTypeDes,pCollisionListItem->typeDescription,pCollisionListItem->typeDescriptionSize);
//         *sizeValue=pCollisionListItem->valueSize;
//         *typeDesSize=pCollisionListItem->typeDescriptionSize;
 }
void traverseKeys(hashTable* pht, void (*pfunc)(void*,size_t)){

}

UINT32 sizeHashTable(hashTable* pht){
    return pht->size;
}