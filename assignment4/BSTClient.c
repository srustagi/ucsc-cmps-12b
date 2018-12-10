

//---------------------------------------------------------------------
// BSTClient.c
// Test client for Binary Search Tree ADT
// 
// This is just an example, you will be doing a lot more tests!
//---------------------------------------------------------------------

// #include "stdio.h"
#include "BST.h"
#include "string.h"

int maxStrLen(BSTObj * T);
BSTObj * findLeftMostChild(BSTObj * T);
BSTObj * get(char * term_to_find, BSTObj * T);
int deleteItem (char *term_to_delete, BSTObj **pT);

int main(int argc, char* argv[]){

    BSTObj *T;
    
    T = NULL;

    printf("inserting a lot of nodes to build a tree \n");
    insert("cat", &T);
    insert("rat", &T);
    insert("bat", &T);
    // insert("crow", &T);
    // insert("dog", &T);
    // insert("dan", &T);
    // insert("dtsh", &T);
    // insert("fox", &T);
    // insert("aaz", &T);
    // insert("zoo", &T);

    deleteItem("cat", &T);
    deleteItem("rat", &T);
    deleteItem("bat", &T);
    // deleteItem("crow", &T);
    // deleteItem("dog", &T);
    // deleteItem("dan", &T);
    // deleteItem("dtsh", &T);
    // deleteItem("fox", &T);
    // deleteItem("aaz", &T);
    // deleteItem("zoo", &T);
    
    inorderTraverse(stdout, T);
    printf("\n");
    inorderTraverse(stdout, T);



    // inorderTraverse(stdout, T);

    // printf("%s\n", (get("cat", T)) -> term);

    // printf("inorder traverse == \n");
    // inorderTraverse(stdout, T);
    // printf("\n== after traverse ==\n");

    // makeEmpty(&T);
    // inorderTraverse(stdout, T);

    return 0;
}

int maxStrLen(BSTObj * T) {
    int result = 0;
    int left_max = 0;
    int right_max = 0;

    if (T == NULL) {
        return result;
    }

    // if (strlen(T -> term) > result)
        result = strlen(T -> term);

    // if (T -> leftChild != NULL)
        left_max = maxStrLen(T -> leftChild);

    // if (T -> rightChild != NULL)
        right_max = maxStrLen(T -> rightChild);

    if (left_max > result)
        return left_max;
    else
        return right_max;
}