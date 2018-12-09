/*
 * File: Dictionary.c
 * Name: Shivansh Rustagi
 * Class: CMPS 12B
 * CruzID: shrustag
 * ID Number: 1651034
 * Description: implementations of Hash Table and all associated helper functions
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Dictionary.h"


// ------ Prototypes -------
unsigned int rotate_left(unsigned int value, int shift);
unsigned int pre_hash(char * input);
int hash(char * key, int tableSize);
bucketList new_bucket_node(char * term);
bucketList find_bucket(bucketList b, char * term);


// ------ Hash Functions ------
/*
 * Function: rotate_left
 * Params:
 *      unsigned int value: the value to be shifted
 *      int shift: the amount to shift the specified value
 * Return values:
 *      The new shifted int
 * Description:
 *      Helper function to shift the bits in an unsigned int by a specified amount
 */
unsigned int rotate_left(unsigned int value, int shift) {
	int sizeInBits = 8 * sizeof(unsigned int);
	shift = shift & (sizeInBits - 1);
	if ( shift == 0 )
		return value;
	return (value << shift) | (value >> (sizeInBits - shift));
}


/*
 * Function: pre_hash
 * Params:
 *      unsigned int value: the value to be shifted
 *      int shift: the amount to shift the specified value
 * Return values:
 *      result: the newly calculated unsigned int
 * Description:
 *      Helper function to convert a string to an unsigned int
 */
unsigned int pre_hash(char* input) {
	unsigned int result = 0xBAE86554;
	while (*input) {
		result ^= *input++;
		result = rotate_left(result, 5);
	}
	return result;
}


/*
 * Function: hash
 * Params:
 * 		HashTableObj * H: the hashtable to get the "size" attribute from to compute the hash of the string
 *      char * key: the string to hash and generate an index for
 * Return values:
 *      the calculated index value for the specified string
 * Description:
 *      Helper function to hash a string, returning an integer in the range 0 to tableSize-1
 */
int hash(char * key, int tableSize) {
	return pre_hash(key) % tableSize;
}


// ------ BucketList Helper Functions ------
/*
 * Function: new_list
 * Params:
 *      char * term: the string to hash and generate an index for
 * Return values:
 *      the calculated index value for the specified string
 * Description:
 *      Helper function to hash a string, returning an integer in the range 0 to tableSize-1
 */
bucketList new_bucket_node(char * term) {
	bucketList node = malloc(sizeof(bucketListObj) + strlen(term)+ 1);// (bucketList) malloc(sizeof(bucketListObj) + (strlen(term) + 1) * sizeof(char));
	assert(node != NULL);
	node -> next = NULL;
	strcpy(node -> item, term);
	return node;
}


/*
 * Function: find_bucket
 * Params:
 * 		bucketList b: the first item in the list
 *      char * term: the string to find in the list
 * Return values:
 *      count: the index of the bucket with the specified term
 * Description:
 *      Helper function which returns either the (zero-based) index of the specified term inside the bucket list, or -1 if the item is not present.
 */
bucketList find_bucket(bucketList b, char * term) {
	bucketList temp = b;
	while ( temp != NULL ) {
		if ( ( strcmp(temp -> item, term) == 0 ) )
			return temp;
		temp = temp -> next;
	}
	return temp;
}

// Hash Table Functions
HashTableObj * newHashTable(int size) {
	int i;
	HashTableObj * table = (HashTableObj *) malloc(sizeof(HashTableObj) + sizeof(bucketListObj) * size);
	assert(table != NULL);
	table -> size = size;
	for ( i = 0; i < size; i++ ) {
		table -> bucket[i] = NULL;
	}
	return table;
}

bool member(HashTableObj *H, char *str) {
	if ( H == NULL ) {
		fprintf(stderr, "Sorry, the passed hash table is a NULL reference, please pass a valid hash table and try again.\n");
		return false;
	}

	if ( str == NULL ) {
		fprintf(stderr, "Sorry, the string passed is a NULL reference, please pass a valid string and try again.\n");
		return false;
	}

	if ( find_bucket((H -> bucket)[hash(str, H -> size)], str) == NULL )
		return false;
	return true;
}

void insert(HashTableObj *H, char *str) {
	int index;

	if ( H == NULL ) {
		fprintf(stderr, "Sorry, the passed hash table is a NULL reference, please pass a valid hash table and try again.\n");
		return;
	}

	if ( str == NULL ) {
		fprintf(stderr, "Sorry, the string passed is a NULL reference, please pass a valid string and try again.\n");
		return;
	}

	index = hash(str, H -> size);
	if ( (H -> bucket)[index] == NULL ) {
		(H -> bucket)[index] = new_bucket_node(str);
	} else {
		bucketList temp = new_bucket_node(str);
		temp -> next = (H -> bucket)[index];
		(H -> bucket)[index] = temp;
	}
}

bool delete(HashTableObj *H, char *str) {
	int index;
	bucketList temp = NULL;
	bucketList delete_temp = NULL;

	if ( H == NULL ) {
		fprintf(stderr, "Sorry, the passed hash table is a NULL reference, please pass a valid hash table and try again.\n");
		return false;
	}
	if ( str == NULL ) {
		fprintf(stderr, "Sorry, the string passed is a NULL reference, please pass a valid string and try again.\n");
		return false;
	}
	if ( !member( H, str ) ) {
		fprintf(stderr, "Sorry, the term is not in the hash table, please try again.\n");
		return false;
	}

	index = hash(str, H -> size);
	temp = (H -> bucket)[index];

	if ( temp == NULL )
        return false;
    // case 2: head needs to be deleted
    if ( ( strcmp(temp -> item, str) == 0 ) ) {
        // set 'delete_temp' to the list head so it can be freed
        delete_temp = temp;
        // set the list head pointer to the next node, since the head is going to be freed
        (H -> bucket)[index] = temp -> next;
        // now that the structure is preserved and the list head pointer has been moved, free the original first node
        free(delete_temp);
        return true;
    }

    // case 3: if the node is anywhere else
    // ensure that the next node is not NULL to prevent illegal memory access
    while ( temp -> next != NULL ) {
        if ( ( strcmp((temp -> next) -> item, str) == 0 ) ) {
            delete_temp = temp -> next;
            temp -> next = temp -> next -> next;
            free(delete_temp);
            return true;
        }
        temp = temp -> next;
    }

	return false;
}

void deleteHashTable (HashTableObj * H) {
	int i;
	bucketList temp = NULL;
	bucketList curr = NULL;
	for ( int i = 0; i < H -> size; i++ ) {
		if((H -> bucket)[i] -> item != NULL) {
			curr = H -> bucket[i];
			while(curr!=NULL){
				temp = curr;
				curr = curr -> next;
				free(temp);
			}
		}
	}
	free(H);
}

void printHashTable(FILE *out, HashTableObj *H) {
	bucketList list;
	int i;
	if (H == NULL) {
		fprintf(stderr, "Hashtable does not exist, so can't print it.\n");
		return;
	}
	if (out == NULL) {
		fprintf(stderr, "File stream to print to does not exist.\n");
		return;
	}
	list = NULL;
	fprintf(out, "Hash table contents\n");
	for ( i = 0; i < H -> size; i++ ) {
		list = H -> bucket[i];
		fprintf(out, "bucket %d\n", i);
		while (list != NULL) {
			fprintf(out, "\tbucket list item = %s\n", list->item);//print the shit and its value
			list = list -> next;
		}
	}
}