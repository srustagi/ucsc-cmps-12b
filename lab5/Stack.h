/*
 * File: Stack.h
 * Name: Shivansh Rustagi
 * Class: CMPS 12M
 * CruzID: shrustag
 * Description: prototypes of Stack functions
 */

#ifndef _STACK_H_INCLUDE_
#define _STACK_H_INCLUDE_

#define MAX_STACK 100


/*
 * Structure: 
 * 		StackObj
 * Params:
 * 		void *items[MAX_STACK]: a pointer to an array which will contain the stack objects
 * 		int top: the index value of the top of the stack
 */
typedef struct StackObj {
    void *items[MAX_STACK];
    int	 top;
} StackObj;


/*
 * Function:
 *      newStack
 * Params:
 *      None
 * Return Values:
 *      S: a pointer to the newly allocated memory for a stack
 * Description:
 *      Constructor for Stacks
 *      use -1 to indicate empty stack
 */
StackObj 	*newStack();


/*
 * Function:
 *      deleteStack
 * Params:
 *      StackObj *S: a pointer to the StackObj which is to be deleted
 * Return Values:
 *      None
 * Description:
 *      Destructor for Stacks
 */
void 		deleteStack(StackObj * S);


/*
 * Function:
 *      stackSize
 * Params:
 *      StackObj *S: a pointer to the StackObj whose size is to be retrieved
 * Return Values:
 *      (S->top + 1): the size of the specified Stack
 * Description:
 *      Accsessor method, gets size of specified Stack
 */
int 		stackSize( StackObj * S);


/*
 * Function:
 *      pop
 * Params:
 *      StackObj *S: a pointer to the StackObj to pop from
 * Return Values:
 *      (S->items[S->top--]) || NULL: a void pointer to the top object which has been popped, or NULL if the stack is empty
 * Description:
 *      Pop the top object off the stack and return a pointer to it
 */
void 		*pop(StackObj *S);


/*
 * Function:
 *      push
 * Params:
 *      StackObj *S: a pointer to the StackObj to push to
 *      void *ref: a pointer to the object to be inserted
 * Return Values:
 *      None
 * Description:
 *      Add objects to stack
 */
void 		push(StackObj *S,  void *ref);


/*
 * Function:
 *      printStack
 * Params:
 *      StackObj *S: a pointer to the StackObj which is to be printed
 * Return Values:
 *      None
 * Description:
 *      Print function for Stacks
 */
void		printStack(StackObj *S);
#endif
