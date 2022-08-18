
/* This file contains hash functions for different C data types*/

// This is a function that hashes a string to an unsigned long long

/* Given a NULL terminated string of characters.
   Returns unsigned long long that contains a hash of the string.
*/
#ifndef THIS_HASH_FUNCTION_FILE
#define THIS_HASH_FUNCTION_FILE

#include "datatypesSizes.h"

UINT64 hash(void *, size_t );

UINT32 hashInts(UINT64 ,UINT32 ,UINT32 , UINT32 );

UINT32 MurmurHash64A ( const void * , int , unsigned int  );

#endif