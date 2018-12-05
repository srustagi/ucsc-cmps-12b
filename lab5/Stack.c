/*
 * File: Stack.c
 * Name: Shivansh Rustagi
 * Class: CMPS 12M
 * CruzID: shrustag
 * Description: implementations of Stack functions
 */

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

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
StackObj *
newStack() {
    StackObj *S;

    S = (StackObj *) malloc ((size_t) sizeof(StackObj));
    S->top = -1;    //nothing in the stack
    return S;
}


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
void
printStack (StackObj *S) {
    int i;
    printf("going to print stack contents %d element \n", S->top + 1);
    for (i = 0; i <= S->top; i++) {
        printf("stack index %d = %p\n", i, S->items[i]);
    }
}


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
void
deleteStack(StackObj * S) {
    S->top = -1;     // being neurotic
    free(S);
}


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
int
stackSize(StackObj * S) {

    return (S->top + 1);

}


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
void
*pop(StackObj *S) {
    if (S->top < 0 ) {  // out of stack items
        //printf("returning nothing, stack empty\n");
        return NULL;
    }
    else {
        //printf("pop returning node");
        return (S->items[S->top--]);
    }
}


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
void
push(StackObj *S,  void *ref) {

    //printf("pushing token ");
    if (S->top <  MAX_STACK - 1) {  // out of stack items
        S->items[++(S->top)] = ref;
    }
    else {
        fprintf(stderr, "sorry out of stack space\n");
    }

}
