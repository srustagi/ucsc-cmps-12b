/*
 * File: Blockchain.h
 * Name: Shivansh Rustagi
 * Class: CMPS 12M
 * CruzID: 1651034
 * Description: prototypes of Blockchain functions
 */

// include guard
#ifndef _BLOCKCHAIN_H_INCLUDE_
#define _BLOCKCHAIN_H_INCLUDE_

#include "Block.h"

/*
 * Structure: 
 * 		BlockchainObj
 * Params:
 * 		Block blocks[BLOCKCHAIN_SIZE]: array of blocks of size BLOCKCHAIN_SIZE
 * 		int size: current size of Blockchain
 */
typedef struct BlockchainObj* Blockchain;


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
Blockchain newBlockchain();


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
void freeBlockchain(Blockchain B);


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
int append(Blockchain B, char* data);


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
int size(Blockchain B);


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
Block get(Blockchain B, int idx);


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
int valid(Blockchain B);


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
void removeLast(Blockchain B);


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
void printBlockchain(FILE* out, Blockchain B);

#endif
