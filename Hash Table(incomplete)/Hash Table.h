#ifndef THIS_HASH_TABLE_FILE
#define THIS_HASH_TABLE_FILE

#include <stdio.h>
#include "datatypesSizes.h"
#include "Doubly_Linked_List.h"

typedef struct slot{
    doublylinkedlist items;
}slot;
typedef struct HashTable{
    slot* slots;
    doublylinkedlist keys;
    UINT32 m;
    UINT32 A,B;
    UINT32 size;
}hashTable;

typedef struct item
{
    void* key;
    void* value;
    size_t keySize;
    size_t valueSize;
    char* typeDescription;
    size_t typeDescriptionSize;
    node* pKeyListNode;
    node* pColisionListNode;
}item;


void createHashTable(hashTable*, UINT32);
void insertKeyValuePair(hashTable*,void*, size_t, void*, size_t,char*, size_t);
void deleteKeyValuePair(hashTable*,void*, size_t);
void getValueOfKey(hashTable*,void*, size_t, void*, size_t);
void traverseKeys(hashTable*, void (*pfunc)(void*,size_t));

#endif