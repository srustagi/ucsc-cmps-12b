/*
 * File: Dictionary.h
 * Name: Shivansh Rustagi
 * Class: CMPS 12B
 * CruzID: shrustag
 * ID Number: 1651034
 * Description: implementations of Hash Table and all associated helper functions
 */

//-----------------------------------------------------------------------------
// Dictionary.h
// Header file for the HashTable ADT
// Array implmentation with  bucket heads that point to linked list of items
// that hash to this bucket
//
// Note that the hash table size is decided by the client and passed to
// the new function that creates the hash table.
//
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#ifndef _DICTIONARY_H_INCLUDE_
#define _DICTIONARY_H_INCLUDE_


typedef struct bucketListObj * bucketList;

typedef struct bucketListObj {
	bucketList next;
	char item[];
} bucketListObj;


// this item will be dynamically allocated newHash,
// must manage the index to stay in allocated array range
typedef struct HashTableObj {
	int	size;		// MUST COME FIRST!!!
	bucketList bucket[];
} HashTableObj;

/*
 * Function: newHashTable
 * Params:
 *      int size: the size of the hash table
 * Return values:
 *      table: a pointer to the memory for the newly allocated memory for the hash table object 
 * Description:
 *      Constructor for the hash table object
 */
HashTableObj * newHashTable(int size);

/*
 * Function: deleteHashTable
 * Params:
 * 		HashTableObj * H: the Hash table to delete
 * Return values:
 *      None
 * Description:
 *      Delete and deallocate the space for every bucket in the hash table, then the table itself
 */
void 		deleteHashTable(HashTableObj * H);

/*
 * Function: member
 * Params:
 * 		HashTableObj * H: the hastable object to check
 *      char * str: the string to find in the Hash Table
 * Return values:
 *      boolean: true if the object is in the hashtable, and false if not
 * Description:
 *      Checks to see if the string is a member of the hashtable or not
 */
bool		member(HashTableObj *H, char *str);

/*
 * Function: insert
 * Params:
 * 		HashTableObj * H: the first item in the list
 *      char * str: the string to find in the list
 * Return values:
 *      None
 * Description:
 *      Inserts the item into the table in the appropriate bucket, at the front of the linkedlist
 */
void 		insert(HashTableObj *H, char *str);

/*
 * Function: delete
 * Params:
 * 		HashTableObj * H: the Hash table to delete from
 *      char * str: the term to delete
 * Return values:
 *      true if the item was deleted, false otherwise
 * Description:
 *      Deletes the item from the hash table
 */
bool		delete(HashTableObj *H, char *str);

/*
 * Function: printHashTable
 * Params:
 * 		FILE * out: the file to print to
 *      HashTableObj * H: the hash table to print
 * Return values:
 *      None
 * Description:
 *      Prints the hash table to the specified file
 */
void		printHashTable(FILE *out, HashTableObj *H);

#endif
