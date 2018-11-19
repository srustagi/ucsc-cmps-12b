/*
 * File: BST.h
 * Name: Shivansh Rustagi
 * Class: CMPS 12B
 * CruzID: shrustag
 * ID Number: 1651034
 * Description: header file with typedef for the BSTObj struct and the function prototypes for tree manipulation
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _BST_H_INCLUDE_
#define _BST_H_INCLUDE_
#define TRUE 1
#define FALSE 0

// Exported reference type
// Tree node to store strings, space must be allocated for the strings
typedef struct BSTObj {
    char               *term;           /* string data in each block */
    struct BSTObj      *leftChild;      /* ptr to left child */
    struct BSTObj      *rightChild;     /* ptr to right child */
} BSTObj;


/*
 * Function: insert
 * Params:
 *      char * new_data: the String to insert into the tree
 *      BSTObj ** pBST: the pointer to the address of the BST to insert into
 * Return values:
 *      None
 * Description:
 *      Inserts the specified data into a new node into the tree.
 */
void insert(char *new_data,  BSTObj **pBST);


/*
 * Function: inorderTraverse
 * Params:
 *      FILE * out: the file to write to
 *      BSTObj * T: the BST to print
 * Return values:
 *      None
 * Description:
 *      Prints the tree using an inorder traversal.
 */
void inorderTraverse(FILE *out, BSTObj *T);


/*
 * Function: preorderTraverse
 * Params:
 *      FILE * out: the file to write to
 *      BSTObj * T: the BST to print
 * Return values:
 *      None
 * Description:
 *      Prints the tree using a preorder traversal.
 */
void preorderTraverse(FILE *out, BSTObj *T);


/*
 * Function: postorderTraverse
 * Params:
 *      FILE * out: the file to write to
 *      BSTObj * T: the BST to print
 * Return values:
 *      None
 * Description:
 *      Prints the tree using a postorder traversal.
 */
void postorderTraverse(FILE *out, BSTObj *T);


/*
 * Function: inorderLeaves
 * Params:
 *      FILE * out: the file to write to
 *      BSTObj * T: the BST whose leaves to print
 * Return values:
 *      None
 * Description:
 *      Prints the leaves of the BST using a preorder traversal.
 */
void inorderLeaves(FILE *out, BSTObj *T);


/*
 * Function: find
 * Params:
 *      char * term_to_find: the term to find in the BST
 *      BSTObj * T: the BST to search
 * Return values:
 *      TRUE or FALSE as defined in BST.h
 * Description:
 *      Searches the BST for the specifed value.
 */
int find(char *term_to_find, BSTObj *T);
  

/*
 * Function: treeHeight
 * Params:
 *      BSTObj * T: the tree whose height to calculate
 *      int height: the height
 * Return values:
 *      TRUE or FALSE as defined in BST.h
 * Description:
 *      Searches the BST for the specifed value.
 */
int treeHeight(BSTObj *T, int height);


/*
 * Function: treeHeight
 * Params:
 *      BSTObj * T: the tree to copy
 * Return values:
 *      temp: a pointer to a BST
 * Description:
 *      Creates a memory independent copy of BST T.
 */ 
BSTObj * copyTree(BSTObj *T);


/*
 * Function: makeEmpty
 * Params:
 *      BSTObj ** pT: the tree to empty
 * Return values:
 *      None
 * Description:
 *      Empty out the tree: deallocate space and NULL the pointer to it.
 */
void makeEmpty(BSTObj **pT);

#endif
