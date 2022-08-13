/* This file contains hash functions for different C data types*/

// This is a function that hashes a string to an unsigned long long

/* Given a NULL terminated string of characters.
   Returns unsigned long long that contains a hash of the string.
*/
#include "datatypesSizes.h"


UINT64 hash(void *type, size_t size)
{
    UINT64 hash = 5381;
    INT32 c;
    INT8* unit= (INT8*)type;
    for (int i = 0; i < size; i++)
    {
        c = *unit;
        unit++;
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c *///33 is a magic number. Explaination not provided.
    }
    return hash;
}

// This is a function that hashes integral types to unsigned long long

unsigned long long hashInts(int key,int m){
    unsigned long long hash;
    static unsigned int a,b;
    unsigned long long p = 9999999997777777333L;
    hash = (((((unsigned long long)a)*((unsigned long long)key)+((unsigned long long)b))%p)%m);
    return hash;
}
// This is a function that hashes floating point to unsigned long long
unsigned long long hashFLoats(double key,int m){
    unsigned long long* pkey = &key;
    return hashInts(*pkey,m);
}