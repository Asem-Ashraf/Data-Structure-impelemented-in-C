#ifndef THIS_HASH_TABLE_FILE
#define THIS_HASH_TABLE_FILE

#include <stdio.h>
#include "datatypesSizes.h"
#include "Doubly_Linked_List.h"
#include "Hash Functions.h"
#pragma
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

typedef struct item{
    void* key;
    void* value;
    void* typeDescription;
    node* pKeyListNode;
    node* pColisionListNode;
    size_t keySize;
    size_t valueSize;
    size_t typeDescriptionSize;
}item;


UINT8  createHashTable     (hashTable*, UINT32);
UINT8  insertKeyValuePair  (hashTable*, void*, size_t,  void*, size_t,  char*, size_t);
UINT8  removeKey           (hashTable*, void*, size_t);
void   getValue            (hashTable*, void*, size_t,  void**, size_t*,  char**, size_t*);
void   traverseKeys        (hashTable*, void (*pfunc)(void*,size_t));
UINT8  destroyHashTable    (hashTable*);
UINT32 sizeHashTable       (hashTable*);
#endif