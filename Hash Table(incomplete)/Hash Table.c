#include "Hash Table.h"


void createHashTable(hashTable* pht, UINT32 m){
    pht->slots=(slot*)malloc(m*sizeof(slot));
    intializeDoublyLinkedList(&(pht->keys));
    for (size_t i = 0; i < m; i++)
    {
        intializeDoublyLinkedList(&pht->slots[i].items);
    }
    pht->m=m;
    pht->size=0;
}
void insertKeyValuePair(hashTable* pht, void* pkey, size_t sizeKey, void* pvalue, size_t sizeValue, char* typeDes, size_t typeDesSize){
    UINT32 index = hashInts(hash(pkey,sizeKey),pht->m);

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
    allocNode(pCollisionListNode);
    insertLast(&(pht->slots[index].items),pCollisionListNode);

    node* pKeyListNode;
    allocNode(pKeyListNode);
    insertLast(&pht->keys,pKeyListNode);

    pCollisionListNode->value=collisionListItem;
    pKeyListNode->value=collisionListItem;

    collisionListItem->pColisionListNode=pCollisionListNode;
    collisionListItem->pKeyListNode=pKeyListNode;

    pht->size++;
}
void deleteKeyValuePair(hashTable* pht, void* pkey, size_t sizeKey){
    UINT32 index = hashInts(hash(pkey,sizeKey),pht->m);
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
    UINT32 index = hashInts(hash(pkey,sizeKey),pht->m);
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