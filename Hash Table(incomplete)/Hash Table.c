#include "Hash Table.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
UINT8 findNodeByKey(hashTable*, void*, size_t,node*);


void createHashTable(hashTable* pht, UINT32 m){
    pht->slots=(slot*)malloc(m*sizeof(slot));
    intializeDoublyLinkedList(&(pht->keys));
    for (size_t i = 0; i < m; i++)
    {
        intializeDoublyLinkedList(&pht->slots[i].items);
    }
    pht->m=m;
    pht->size=0;
    srand((unsigned int)time(NULL));
    label:
    pht->A=rand();
    pht->B=rand();
    if (pht->A%2==0||pht->A%5==0) goto label;
    pht->A=1;
    pht->B=0;
}
void insertKeyValuePair(hashTable* pht, void* pkey, size_t sizeKey, void* pvalue, size_t sizeValue, char* typeDes, size_t typeDesSize){
    UINT32 HASHERR = MurmurHash64A(pkey,sizeKey,5381);
    UINT32 index = hashInts(HASHERR,pht->m,pht->A,pht->B);
    item* collisionListItem=(item*)malloc(sizeof(item));
    void* valuecopy=malloc(sizeValue);
    void* keycopy=malloc(sizeKey);
    void* typedescopy=malloc(typeDesSize);
    memcpy(valuecopy,pvalue,sizeValue);
    memcpy(keycopy,pkey,sizeKey);
    memcpy(typedescopy,typeDes,typeDesSize);
    collisionListItem->value=valuecopy;
    collisionListItem->key=keycopy;
    collisionListItem->keySize=sizeKey;
    collisionListItem->valueSize=sizeValue;
    collisionListItem->typeDescription=typedescopy;
    collisionListItem->typeDescriptionSize=typeDesSize;
    
    node* pCollisionListNode;
    pCollisionListNode = (node*)malloc(sizeof(node));
    pCollisionListNode->next=pCollisionListNode->prev=pCollisionListNode->value=NULL;
    //allocNode(pCollisionListNode);
    insertLast(&(pht->slots[index].items),pCollisionListNode);

    node* pKeyListNode;
    pKeyListNode = (node*)malloc(sizeof(node));
    pKeyListNode->next=pKeyListNode->prev=pKeyListNode->value=NULL;
    //allocNode(pKeyListNode);
    insertLast(&(pht->keys),pKeyListNode);

    pCollisionListNode->value=collisionListItem;
    pKeyListNode->value=collisionListItem;

    collisionListItem->pColisionListNode=pCollisionListNode;
    collisionListItem->pKeyListNode=pKeyListNode;

    pht->size++;
}
void deleteKeyValuePair(hashTable* pht, void* pkey, size_t sizeKey){
    UINT32 index = hashInts(hash(pkey,sizeKey),pht->m,pht->A,pht->B);
    node* pCollisionListNode;
    if(findNodeByKey(pht,pkey,sizeKey,pCollisionListNode)){
        free( &((item*)pCollisionListNode->value)->key);
        free( &((item*)pCollisionListNode->value)->value);
        free( &((item*)pCollisionListNode->value)->typeDescription);
        node* pKeyListNode = &((item*)pCollisionListNode->value)->pKeyListNode;
        free(pCollisionListNode->value);
        deleteNode(&(pht->keys),pKeyListNode);
        deleteNode(&(pht->slots[index].items),pCollisionListNode);
        pht->size--;
    }

}
void getValueOfKey(hashTable* pht, void* pkey, size_t sizeKey, void* pvalue, size_t sizeValue){

}
UINT8 findNodeByKey(hashTable* pht, void* pkey, size_t sizeKey,node* pNode){
    UINT32 index = hashInts(hash(pkey,sizeKey),pht->m,pht->A,pht->B);
    INT8* unit=(INT8*)pkey;
    node* nody=pht->slots[index].items.head;
    for (size_t i = 0; i < len(&pht->slots[index].items)-1 ; i++)
    {
        if (sizeKey==((item*)(nody->value))->keySize)
        {
            INT8* key=((item*)(nody->value))->key;
            for (size_t j = 0; j < sizeKey-1; j++)
            {
               if (unit[j]!=key[j])
               {
                    break;
               }
               if (j==sizeKey-1)
               {
                    pNode=nody;
                    return 1;
               }
            }
        }
        nody=nody->next;
    }
    pNode=NULL;
    return 0;
    
}
void traverseKeys(hashTable* pht, void (*pfunc)(void*,size_t)){

}