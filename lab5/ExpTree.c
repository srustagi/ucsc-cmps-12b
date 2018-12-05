/*
 * File: ExpTree.c
 * Name: Shivansh Rustagi
 * Class: CMPS 12M
 * CruzID: shrustag
 * Description: implementations of ExpTree ADT functions
 */

#include "ExpTree.h"
/*
 * Read input string with contains a post-fix expression and buid the corresponding expression evaluation
 *
 * handles input of one post-fix expressio of integers n read from stdin. Examples:
 *   a b c + +    a b - c +   where a,b,c are integers
 * ignores all white space and uses C's sscanf to find acceptable integer formats. Input can flow over
 * multiple lines and is terminated with EOF.
 *
 * This program only handles regular ints on your machine. So if you input very long int values they will be either
 * truncated or wrap around due to overflow, depening on what sscanf does will integer conversion from too long
 * string values.
 *
 * Does not handle overflow in general, so if you have a resulting expression too large for an int, an overflow
 * generate unexpected results.
 *
 */

tokenType convertToken( char *tokenStr, int *tokenVal);

TNode * newTNode(tokenType inputToken, int tokenVal, TNode *op1, TNode *op2);

const char *tokenToStr(tokenType tokenT);

void printNode( TNode * node);


/*
 * Function:
 *      newExpressionTree
 * Params:
 *      None
 * Return Values:
 *      S: a pointer to the newly allocated stack representing the expression tree
 * Description:
 *      Constructor for ExpTree
 */
ExpT *
newExpressionTree() {
    StackObj *S;
    S = newStack();
    return S;
}


/*
 * Function:
 *      deleteTree
 * Params:
 *      TNode * T: a pointer to the Tree node which is to be deleted 
 * Return Values:
 *      None
 * Description:
 *      Destructor for Stacks
 */
void
deleteTree(TNode *T) {

    if (T != NULL) {
        T->value = 0;   // neurotic
        deleteTree(T->leftOperand);
        deleteTree(T->rightOperand);
        free(T);
    }
}


/*
 * Function:
 *      deleteExpressionTree
 * Params:
 *      ExpT *T: a pointer to the tree which is to be deleted
 * Return Values:
 *      None
 * Description:
 *      
 */
void
deleteExpressionTree(ExpT *T) {

    TNode *node;
    StackObj *S = T;

    while ((node = (TNode *) pop(S)) != NULL) {
        deleteTree(node);
    }
    deleteStack(S);
}


/*
 * Function:
 *      printNode
 * Params:
 *      TNode * node: the node to print
 * Return Values:
 *      None
 * Description:
 *      
 */
void
printNode( TNode * node) {

    printf(" node addr = %p, type = %d, value = %d, leftOp = %p, rightOp = %p\n", node, node->type,
           node->value, node->leftOperand, node->rightOperand);

}


/*
 * Function:
 *      convertToken
 * Params:
 *      char * tokenStr: a pointer to the token which is to be converted
 *      int * tokenVal: 
 * Return Values:
 *      retval: the converted token from string to enum
 * Description:
 *      
 */
tokenType
convertToken( char *tokenStr, int *tokenVal) {

    tokenType retVal;
    char      junkChars[MAX_TOKEN_LENGTH];
    int       scanCount;

    // check what the token string might be
    scanCount = sscanf (tokenStr, "%d%s", tokenVal, junkChars);

    if (scanCount == 1) {
        //printf("token is an integer,str is %s, value = %d\n", tokenStr, *tokenVal);
        return OPERAND;
    }
    if (scanCount == 2) {  // check no trailing characters
        fprintf(stderr, "ERROR, unaccceptable format, had some extra characters in the integer %d\n", *tokenVal);
        exit(EXIT_FAILURE);
    }

    if (scanCount > 2 ) {
        fprintf(stderr, "something weird in input parsing, exiting with str = %s\n", tokenStr);
        exit(EXIT_FAILURE);
    }
    // maybe an operator, try and check the format
    else {
        if (strlen(tokenStr) > MAX_OPERATOR_LENGTH) {
            printf("sorry, can't handle operators longer than 1 character\n");
            return END;
        }
        switch (tokenStr[0]) {
        case '+':
            retVal = PLUS;
            break;
        case '-':
            retVal = MINUS;
            break;
        case '*':
            retVal = MUL;
            break;
        case '/':
            retVal = DIV;
            break;
        default:
            fprintf(stderr, "sorry, don't recognize this operator %c\n", tokenStr[0]);
            exit(EXIT_FAILURE);
        }
        //printf("got operator = %d\n", retVal);
        return retVal;
    }

}

/*
 * Function:
 *      newTNode
 * Params:
 *      tokenType inputToken:
 *      int tokenVal: 
 *      Tnode * op1:
 *      TNode * op2: 
 * Return Values:
 *      node: a pointer to a node containing the passed information
 * Description:
 *      
 */
TNode *
newTNode(tokenType inputToken, int tokenVal, TNode *op1, TNode *op2)  {

    TNode *node;

    node = (TNode *) malloc ((size_t)(sizeof(TNode)));
    node->type = inputToken;
    if (inputToken == OPERAND ) { // this will be a leaf
        node->value = tokenVal;
        node->leftOperand = NULL;
        node->rightOperand = NULL;
    }
    else { // this will be an internal node
        node->leftOperand = op1;
        node->rightOperand = op2;
    }
    //printf("tree node created\n");
    //printNode(node);
    return node;
}


/*
 * Function:
 *      tokenToStr
 * Params:
 *      tokenType tokenT: the tokentype to convert
 * Return Values:
 *      tokenChars[tokenT]: the converted token
 * Description:
 *     
 */
const char *
tokenToStr(tokenType tokenT) {

    const static char *tokenChars[] = {"+", "-", "*",  "/", "^D"};
    return tokenChars[tokenT];

}


/*
 * Function:
 *      expressionEval
 * Params:
 *      TNode * T: a pointer to the node which to evaluate 
 * Return Values:
 *      
 * Description:
 *      
 */
int
expressionEval(TNode *T) {
    if ( T == NULL ) {
        return 0;
    }
    else {
        if( T->leftOperand == NULL && T->rightOperand == NULL){
            return T->value;
        }

        else if( T->leftOperand != NULL && T->rightOperand != NULL){

            int left = expressionEval(T->leftOperand);
            int right = expressionEval(T->rightOperand);
            
            if (T -> type == PLUS)
                return (left + right);

            if (T -> type == MINUS)
                return (left - right);

            if (T -> type == MUL)
                return (left * right);

            if (T -> type == DIV) {
                if ( right == 0 ){
                    fprintf(stderr, "dividing by 0 warning");
                    return 0;
                }
                else {
                    return (left / right);
                }
            }
        }
    }
}


/*
 * Function:
 *      expressionEval
 * Params:
 *      TNode * T: a pointer to the node which to evaluate 
 * Return Values:
 *      
 * Description:
 *      
 */
void
inorderTraverse(FILE *out, TNode  *T) {
    if ( out == NULL ){
        fprintf( stderr , "inorderTraverse - Handle to output file is NULL");
        return;
    }

    if ( T->type == OPERAND){
        fprintf(out, "(%i)", T->value);
    }

    else{
        fprintf( out ,"(");
        inorderTraverse( out , T->leftOperand);
        fprintf(out ,"%s" , tokenToStr(T->type));
        inorderTraverse( out , T->rightOperand);
        fprintf( out ,")");
    }
}

void
outputExpressionTree(ExpT *T) {


    TNode *node;
    StackObj *S = T;

    // check if the expression tree is correct for evaluation
    // check overflow or underflow of operands
    if (stackSize(S) > 1 ) {
        fprintf (stderr, "ERROR extra operands in expression\n");
    }
    else {
        node = (TNode *) pop(S); // pop off the node to get access to it
        inorderTraverse(stdout, node);
        printf(" = %d\n", expressionEval(node));
        push(S, node);       // push the node back on so the stack retains the tree for deletion
    }

}

void
inputExpressionTree(ExpT *T) {

    char  inputToken[MAX_TOKEN_LENGTH + 1];
    tokenType token;
    TNode  *node, *op1, *op2;
    int   tokenVal;
    StackObj *S;

    S = T;
    while (scanf( "%s", inputToken) > 0) {

        //printf("input token = %s\n", inputToken);

        token = convertToken (inputToken, &tokenVal);
        //printf( "converted token %d \n", token);
        if (token == OPERAND ) {
            if ((node = newTNode(OPERAND, tokenVal, NULL, NULL)) == NULL)
                fprintf(stderr, "problem creating node\n");
            else
                push(S, (void *)node);
        }
        else {
            if ((op2 = pop(S)) == NULL) {
                fprintf(stderr, "sorry, out of operands for operators\n");
                exit(EXIT_FAILURE);
            }

            if ((op1 = pop(S)) == NULL) {
                fprintf(stderr, "sorry, out of operands for operator\n");
                exit(EXIT_FAILURE);
            }
            node = newTNode(token, 0, op1, op2);
            push(S, node);
        }
    }
}
