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

    printf("inorder traverse == \n");
    inorderTraverse(stdout, T);
    printf("\n== after traverse ==\n");

    makeEmpty(&T);

    printf("inorder traverse == \n");
    inorderTraverse(stdout, T);
    printf("\n== after traverse ==\n ");

    // printf("%d\n", treeHeight(T, 0));
   
    return 0;
}
