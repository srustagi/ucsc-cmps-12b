

//---------------------------------------------------------------------
// BSTClient.c
// Test client for Binary Search Tree ADT
// 
// This is just an example, you will be doing a lot more tests!
//---------------------------------------------------------------------

// #include "stdio.h"
#include "BST.h"
#include "string.h"

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
    insert("crow", &T);
    insert("dog", &T);
    insert("dan", &T);
    insert("dtsh", &T);
    insert("fox", &T);
    insert("aaz", &T);
    insert("zoo", &T);
    
    inorderTraverse(stdout, T);
    printf("\n");

    deleteItem("cat", &T);
    deleteItem("rat", &T);
    deleteItem("bat", &T);
    deleteItem("crow", &T);
    deleteItem("dog", &T);
    deleteItem("dan", &T);
    deleteItem("dtsh", &T);
    deleteItem("fox", &T);
    deleteItem("aaz", &T);
    deleteItem("zoo", &T);
    
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
