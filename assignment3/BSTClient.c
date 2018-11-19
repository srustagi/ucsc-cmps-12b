

//---------------------------------------------------------------------
// BSTClient.c
// Test client for Binary Search Tree ADT
// 
// This is just an example, you will be doing a lot more tests!
//---------------------------------------------------------------------

#include "stdio.h"
#include "BST.h"

int main(int argc, char* argv[]){

    BSTObj  *T;
    
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

    printf("%d\n", treeHeight(T, 0));

    BSTObj *temp;
    temp = copyTree(T);
    insert("gay", &temp);
    printf("%d\n", find("gay", temp));
    printf("%d\n", find("bhenchod", temp));
    inorderTraverse(stdout, temp);


    printf("inorder traverse == \n");
    inorderTraverse(stdout, T);
    printf("\n== after traverse ==\n");

    makeEmpty(&T);
    makeEmpty(&temp);
    inorderTraverse(stdout, T);

    return 0;
}
