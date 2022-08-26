#ifndef THIS_HASH_TABLE_FILE
#define THIS_HASH_TABLE_FILE

#include <stdio.h>
#include "datatypesSizes.h"
#include "Doubly_Linked_List.h"
#include "Hash Functions.h"
#pragma
/*
 *  This is a general collision hash table that can map anything to anything given their sizes.
 *  The key is stored in the form of a pointer to a copy of the key given in the insert function.
 *  the value and type description are also stored the same way.
 *  These copies are accessed through the getValue() function.
 *  Any manipulations in these copies will reflect in the actual data stored in the table.
 *  The insertKeyValuePair() function checks to see if the key exists first. If it does, then it 
 *  overrides its value with the new one. This gives 2 ways to edit the value, type description and thier sizes.
 *  The type description is an important attribute because it is the only way of knowing the type of the key and value.
 *  It is preferably a string in the format "{key type}:{value type}" but either of them could be omitted
 *  if the its type is the same for each element. Numbers could also be used to refer to the type. It is up to the programmer
 *  to decide what the format is and how to use it. This was impelemeted because there was no way of knowing
 *  the type of the variable that am getting from the getValue() function. Now, a switch case could be used 
 *  on all the type that the user could enter in the table to do the correct operations based on the type.
 *  The type description is not given as data to the hash function.
*/

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
    UINT32 index;
}item;

// Given a Hashtable pointer and the size of it.
// The function creates the hash table and dynamically allocates its attributes and sets the number of its collision containers to that size.

UINT8  createHashTable     (hashTable*, UINT32);

// Given a key-value pair and thier sizes.
// the function inserts a copy of them into a collision container.
// If the key already exists, its value  and type description will be updated.

UINT8  insertKeyValuePair  (hashTable*, void*, size_t,  void*, size_t,  char*, size_t);

// Given a key and its size.
// The key, its value, type description and thier sizes are deleted from the table.
// returns 1 if successful.
// returns 0 otherwise.

UINT8  removeKey           (hashTable*, void*, size_t);

// Given a key and its size.
// Returns the value, type description and thier sizes.
// Note: these are the acutal data stored in the table. 
//       Any changes to them will be reflected in the next call.

void   getValue            (hashTable*, void*, size_t,  void**, size_t*,  char**, size_t*);

void   traverseKeys        (hashTable*, void (*pfunc)(const void*,size_t,void*,size_t,void*,size_t));

UINT8  destroyHashTable    (hashTable*);
UINT32 sizeHashTable       (hashTable*);

#define indexer(pht,pkey,sizeKey) hashInts(MurmurHash64A(pkey,sizeKey,5),pht->m,pht->A,pht->B)
#define getIndexByKey(pht,pkey,sizeKey) indexer(pht,pkey,sizeKey)
#define sizeHashTable(pht) pht->size
#endif