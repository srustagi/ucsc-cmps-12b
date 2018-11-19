/*
 * File: Block.h
 * Name: Shivansh Rustagi
 * Class: CMPS 12M
 * CruzID: shrustag
 * Description: prototypes of Block functions
 */

#include <stdio.h>
#include <stdlib.h>
// include guard to avoid redefinitions
#ifndef _BLOCK_H_INCLUDE_
#define _BLOCK_H_INCLUDE_

/*
 * Structure: 
 * 		BlockObj
 * Params:
 * 		char* data: the data contained in this block
 * 		int id: the id of the block
 * 		long hash: the hash of the previous block
 */typedef struct BlockObj* Block;


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
Block newBlock(char* data, int id, long hash);


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
void freeBlock(Block B);


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
char* data(Block B);


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
long previousHash(Block B);


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
long hash(Block B);


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
void printBlock(FILE* out, Block B);

#endif
