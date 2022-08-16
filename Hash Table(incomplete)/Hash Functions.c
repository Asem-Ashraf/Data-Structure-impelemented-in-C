/* This file contains hash functions for different C data types*/

// This is a function that hashes a string to an unsigned long long

/* Given a NULL terminated string of characters.
   Returns unsigned long long that contains a hash of the string.
*/
#ifndef THIS_HASH_FUNCTION_FILE
#define THIS_HASH_FUNCTION_FILE
#include "datatypesSizes.h"
#include <math.h>

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

UINT32 hashInts(UINT32 key,UINT32 m,UINT32 A, UINT32 B){
    UINT64 p = 180811181061181081L;
    return  ((((UINT64)A)*((UINT64)key)+((UINT64)B))%m);

}


//typedef unsigned INT64 uint64;

// 64-bit hash for 64-bit platforms

UINT32 MurmurHash64A ( const void * key, int len, unsigned int seed )
{
    const unsigned int m = 0x5bd1e995;
    const int r = 24;

    // Initialize the hash to a 'random' value

    unsigned int h = seed ^ len;

    // Mix 4 bytes at a time into the hash

    const unsigned char * data = (const unsigned char *)key;

    while(len >= 4)
    {
        unsigned int k = *(unsigned int *)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    // Handle the last few bytes of the input array

    switch(len)
    {
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0];
            h *= m;
    };

    // Do a few final mixes of the hash to ensure the last few
    // bytes are well-incorporated.

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

#endif