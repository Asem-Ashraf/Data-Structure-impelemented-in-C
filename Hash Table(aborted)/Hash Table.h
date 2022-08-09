#ifndef THIS_HASH_TABLE_FILE
#define THIS_HASH_TABLE_FILE

#include "Doubly_Linked_List.h"
#define valuetype int
#define keytype char*
typedef struct slot{
    int free;
    doublylinkedlist items;
}slot;

typedef struct item
{
    unsigned long long key;
    valuetype item;
}item;
/* Given a size of the hash table elements.
   Returns an array of slots to insert keyvalue pairs in.
*/
slot* createHashTable(int);
void insertKeyValuePair(keytype,valuetype);
void deleteKeyValuePair(keytype,valuetype);
void getValueOfKey(keytype);

#endif