/*
 * File: Block.c
 * Name: Shivansh Rustagi
 * Class: CMPS 12M
 * CruzID: 1651034
 * Description: implementations of Block functions
 */
#include <assert.h>
#include <string.h>
#include "Block.h"

/*
 * Structure: 
 * 		BlockObj
 * Params:
 * 		char* data: the data contained in this block
 * 		int id: the id of the block
 * 		long hash: the hash of the previous block
 */
struct BlockObj {
	char* data;
	int id;
	long hash;
};


/* 
 * Function:
 * 		newBlock
 * Params:
 * 		char* data: the data contained in this block
 * 		int id: the id of the block
 * 		long has: the hash of the previous block to be stored in this block
 * Return Values:
 * 		block_ptr: a pointer to the newly allocated memory for the block with the specifed data
 * Description:
 * 		Constructor for Blocks
 */
Block newBlock(char* data, int id, long hash) {
	// allocate memory
	Block block_ptr = (Block) malloc(sizeof(struct BlockObj));
	// check that allocation was successful
	assert(block_ptr != NULL);
	// set instance fields
	block_ptr -> data = data;
	block_ptr -> id = id;
	block_ptr -> hash = hash;
	// success
	return block_ptr;
}


/* 
 * Function:
 * 		freeBlock
 * Params:
 * 		Block B: the block to be freed
 * Return values:
 *		None
 * Description:
 * 		Deallocates the memory for a specific block
 */
void freeBlock(Block B) {
	// make sure B exists
	if ( B != NULL ) {
		free(B);
		return;
	}
	// handle NULL pointer free attempt
	else {
		fprintf(stderr, "The Block passed was NULL, please pass a valid block.\n");
		return;
	}
}


/* 
 * Function:
 * 		data
 * Params:
 * 		Block B: the block to retrieve the data from
 * Return values:
 *		result: the data from the block
 * Description:
 * 		Retrieve the data from a specified block
 */
char* data(Block B) {
	// initialize the string to NULL pointer
	char* result = NULL;
	// if Block is valid, carry out with the operation
	if ( B != NULL ) {
		result = B -> data;
	}
	// handle NULL pointer
	else {
		fprintf(stderr, "The Block passed was NULL, please pass a valid block.\n");
	}
	// success
	return result;
}


/* 
 * Function:
 * 		previousHash
 * Params:
 * 		Block B: the block to retrieve the previous hash from
 * Return values:
 *		result: the hash value of the previous block
 * Description:
 * 		Retrieve the data from a specified block, if block is NULL, return -1
 */
long previousHash(Block B) {
	long result = -1;
	// retrieve data
	if ( B != NULL ) {
		result = B -> hash;
	}
	// Handle NULL Block retrieval attempt 
	else {
		fprintf(stderr, "The Block passed was NULL, please pass a valid block.\n");
	}
	// success
	return result;
}


/* 
 * Function:
 * 		hash
 * Params:
 * 		Block B: the block to calculate the hash for
 * Return values:
 *		result: the calculated hash value
 * Description:
 * 		Calculate the hash value of a block, if block is NULL, return -1
 */
long hash(Block B) {
	long result = -1;
	int index;
	if (B != NULL) {
		// add the ID and previous hash to the current hash
		result = (B -> id) + (B -> hash);
		// add each character from the string to the hash
		for (index = 0; index < strlen(B -> data); index++) {
			result += ((int) (B -> data)[index]);
		}
	}
	// handle NULL pointer hash calculation attempt
	else {
		fprintf(stderr, "The Block passed was NULL, please pass a valid block.\n");
	}
	// success
	return result;
}


/* 
 * Function:
 * 		printBlock
 * Params:
 * 		FILE* out: the file to write to
 * 		Block B: the block to print
 * Return values:
 *		None
 * Description:
 * 		Print the specified Block in the format: `id:data`
 */
void printBlock(FILE* out, Block B) {
	fprintf(out, "%d:%s\n", B -> id, B -> data);
}
