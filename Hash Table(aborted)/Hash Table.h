#ifndef THIS_HASH_TABLE_FILE
#define THIS_HASH_TABLE_FILE

#include "datatypesSizes.h"
#include <stdio.h>
#include "Doubly_Linked_List.h"

typedef struct HashTable{
    slot* slots;
    doublylinkedlist keys;

}hashTable;
typedef struct slot{
    UINT8 isEmpty;
    doublylinkedlist items;
}slot;
typedef struct key{
    void* key;
    size_t keySize;
}key;
typedef struct item
{
    void* key;
    void* item;
    size_t keySize;
    size_t itemSize;
}item;





/* Given a size of the hash table elements.
   Returns an array of slots to insert keyvalue pairs in.
*/
void createHashTable(hashTable*, UINT32);
void insertKeyValuePair(void* ,size_t,void*,size_t);
void deleteKeyValuePair(void*,size_t);
void getValueOfKey(void*,size_t);

#endif