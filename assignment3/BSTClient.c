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

    // printf("%d\n", find("cat", T));
    
    BSTObj  *temp_tree;
    temp_tree = NULL;
    temp_tree = copyTree(T);

    makeEmpty(&T);
    makeEmpty(&temp_tree);

    // printf("inorder traverse == \n");
    // inorderTraverse(stdout, T);
    // printf("\n== after traverse ==\n");

    // printf("%p\n", T);
   
    printf("%d\n", treeHeight(T, 0));

    return 0;
}
