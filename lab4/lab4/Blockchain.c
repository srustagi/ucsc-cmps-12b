/*
 * File: Blockchain.c
 * Name: Shivansh Rustagi
 * Class: CMPS 12M
 * CruzID: shrustag
 * Description: implementations of Blockchain functions
 */

#include <assert.h>
#include "Blockchain.h"
// Blockchain size, no magic numbers
#define BLOCKCHAIN_SIZE 100

/*
 * Structure: 
 * 		BlockchainObj
 * Params:
 * 		Block blocks[BLOCKCHAIN_SIZE]: array of blocks of size BLOCKCHAIN_SIZE
 * 		int size: current size of Blockchain
 */
struct BlockchainObj {
	Block blocks[BLOCKCHAIN_SIZE];
	int size;
};


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
 * 		newBlockchain
 * Params:
 * 		None
 * Return values:
 *		chain: a pointer to the newly allocated memory for the Blockchain object
 * Description:
 * 		Constructor for the Blockchain object
 */
Blockchain newBlockchain() {
	Blockchain chain = NULL;
	int index;
	// allocate memory
	chain = (Blockchain) malloc(sizeof(struct BlockchainObj));
	// check for allocation successful
	assert(chain != NULL);
	// set size to zero
	chain -> size = 0;
	// NULL each Block object in the chain
	for ( index = 0; index < BLOCKCHAIN_SIZE; index++ ) {
		(chain -> blocks)[index] = NULL;
	}
	// success
	return chain;
}


/* 
 * Function:
 * 		freeBlockchain
 * Params:
 * 		Blockchain B: the Blockchain to be freed
 * Return values:
 *		None
 * Description:
 * 		Deallocate the entire Blockchain
 */
void freeBlockchain(Blockchain B) {
	int index;
	if ( B == NULL ) {
		fprintf(stderr, "The Blockchain is NULL, please pass a valid Blockchain and try again.\n");
		return;
	}
	else {
		for ( index = 0; index < (size(B)); index++ ) {
			free(get(B, index));
		}
		free(B);
	}
}


/* 
 * Function:
 * 		append
 * Params:
 * 		Blockchain B: the Blockchain to which the new Block will be appended
 * 		char* data: the data for the new Block which is to be added to the chain
 * Return values:
 *		the size of the chain if successful, or 0 otherwise
 * Description:
 * 		Append a new Block to the chain with given data
 */
int append(Blockchain B, char* data) {
	Block temp;
	int result;
	// handle full Blockchain
	if ( B == NULL ) {
		fprintf(stderr, "The Blockchain is NULL, please pass a valid Blockchain and try again.\n");
		result = 0;
	}
	if ( data == NULL ) {
		fprintf(stderr, "The data is NULL, please pass valid data and try again.\n");
		result = 0;
	}
	if ( size(B) == BLOCKCHAIN_SIZE ) {
		fprintf(stderr, "Sorry, the Blockchain is full. Please remove some Blocks or use a different chain to continue\n");
		result = 0;
	}
	// empty chain
	else if ( (size(B)) == 0 ) {
		// first block in the chain should have an id and a hash of zero
		(B -> blocks)[0] = newBlock(data, 0, 0);
		(B -> size)++;
		result = size(B);
	}
	// non-empty chain
	else {
		temp = get(B, size(B) - 1);
		(B -> blocks)[size(B)] = newBlock(data, 1 + (temp -> id), hash(temp));
		(B -> size)++;
		result = size(B);
	}
	// success
	return result;
}


/* 
 * Function:
 * 		size
 * Params:
 * 		Blockchain B: the Blockchain of which the size is being calculated
 * Return values:
 *		B -> size: the size of the chain
 * Description:
 * 		Returns the size of the chain, -1 if not successful
 */
int size(Blockchain B) {
	if ( B != NULL ) {
		return B -> size;
	}
	else {
		fprintf(stderr, "The Blockchain is NULL, please pass a valid Blockchain and try again.\n");
		return -1;
	}
}


/* 
 * Function:
 * 		get
 * Params:
 * 		Blockchain B: the Blockchain to retrieve the Block from
 * 		int idx: the index for the Block which is to be retrieved
 * Return values:
 *		(B -> blocks)[idx]: the Block at position `idx`
 * Description:
 * 		Get the specified block at index idx. Returns a block with hash, id as -1 and string as NULL as failed result
 */
Block get(Blockchain B, int idx) {
	if ( B == NULL ) {
		fprintf(stderr, "The Blockchain is NULL, please pass a valid Blockchain and try again.\n");
		return newBlock(NULL, -1, -1);
	}
	else if ( idx < 0 || idx > (BLOCKCHAIN_SIZE - 1) ) {
		fprintf(stderr, "Sorry, this is not a valid index. Please pass an index equal to or greater than zero, and less than %d.\n", BLOCKCHAIN_SIZE);
		return newBlock(NULL, -1, -1);
	}
	else {
		if( (B -> blocks)[idx] == NULL ) {
			fprintf(stderr, "The Block to get is NULL, please add Blocks until positiion %d and try again\n", idx);
			return newBlock(NULL, -1, -1);
		} else {
			return (B -> blocks)[idx];
		}
	}
}


/* 
 * Function:
 * 		valid
 * Params:
 * 		Blockchain B: the Blockchain to validate
 * Return values:
 *		1 or 0; 1 for valid, 0 for invalid
 * Description:
 * 		Check if the chain is a valid chain by comparing the previous hash values to the hash of the previous block
 */
int valid(Blockchain B) {
	int index;
	// handle NULL Blockchain
	if ( B == NULL ) {
		fprintf(stderr, "Sorry, this is an empty blockchain. Please pass a valid blockchain and continue.\n");
		return 0;
	}
	// handle Blockchain with only one element
	if ( get(B, 1) == NULL ) {
		if ( previousHash(get(B, 0)) == 0 )
			return 1;
		else
			return 0;
	}
	// loop through Blockchain and check if the whole thing is valid
	else {
		for (index = 1; index < size(B) - 1; index++) {
			if ( previousHash(get(B, index)) != hash(get(B, index - 1)) ) {
				return 0;
			}
		}
	}
	return 1;
}


/* 
 * Function:
 * 		removeLast
 * Params:
 * 		Blockchain B: the Blockchain to shorten
 * Return values:
 *		None
 * Description:
 * 		Remove the last Block in the specified Blockchain
 */
void removeLast(Blockchain B) {
	if ( B == NULL ) {
		fprintf(stderr, "The Blockchain is NULL, please pass a valid Blockchain and try again.\n");
		return;
	}
	else if ( size(B) == 0 ) {
		fprintf(stderr, "The Blockchain is empty; please add Blocks, then remove.\n");
		return;	
	} 
	else {
		freeBlock((B -> blocks)[--(B -> size)]);
	}
}


/* 
 * Function:
 * 		printBlockchain
 * Params:
 * 		FILE* out: the file to write to
 * 		Blockchain B: the Blockchain to print
 * Return values:
 *		None
 * Description:
 * 		Print the entire Blockchain
 */
void printBlockchain(FILE* out, Blockchain B) {
	int index;
	if ( B == NULL ) {
		fprintf(stderr, "The Blockchain is NULL, please pass a valid Blockchain and try again.\n");
	}
	for (index = 0; index < (size(B)); index++) {
		printBlock(out, get(B, index));
	}
}
