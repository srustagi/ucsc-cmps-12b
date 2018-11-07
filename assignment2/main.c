#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listUtil.h"


void test0();
void test1();
void test2();


int main () {

    /* add a bunch tests here to check for various cases of list functions */

    // test0();
    // test1();
    test2();
    return (EXIT_SUCCESS);
}



void test0() {

    NodeObj *list = NULL;
    NodeObj *node1 = NULL;
    // NodeObj *node2 = NULL;
    // NodeObj *node3 = NULL;
    int i;

    // printf("bad insert with bad parameters- should catch these errors to stderr \n");
    
    insert(NULL, node1);
    insert (&list, NULL);

    // printf("test a bunch of unordered inserts, 1,2,3, ...9 increasing order \n");
    // printf("list traversal should be in order 1,2,3, ...9\n");
    
//     node2 = create_new_node(2);
//     node3 = create_new_node(3);
//     ordered_insert(&list, node2);
//     ordered_insert(&list, node3);
    for (i = 1; i < 10 ; i++) {
        node1 = create_new_node(i);
        ordered_insert(&list, node1);
    }
    traverse_print(list);
    // delete_all(list);
    // traverse_print(list);

    printf("end test 0 \n");
}

void test1() {

    NodeObj *node1 = NULL;
    NodeObj *list = NULL;
    int i;

    printf("test a bunch of inserts, 1,2,3, ,,,9 increasing order \n");
    printf("list traversal should be in order 1,2,3,...9\n");

    for (i = 10; i > 0 ; i--) {
        node1 = create_new_node(i);
        insert(&list, node1);
    }
    reverse_print(list);

    delete(&list, node1);

    traverse_print(list);

    printf("end test 1 \n");
}

void test2(){
    NodeObj *list = NULL;

    NodeObj *node1 = NULL;
    node1 = create_new_node(1);
    NodeObj *node2 = NULL;
    node2 = create_new_node(2);
    NodeObj *node3 = NULL;
    node3 = create_new_node(3);
    NodeObj *node4 = NULL;
    node4 = create_new_node(4);
    NodeObj *node5 = NULL;
    node5 = create_new_node(5);
    NodeObj *node6 = NULL;
    node6 = create_new_node(6);
    
    ordered_insert(&list, node1);
    ordered_insert(&list, node4);
    ordered_insert(&list, node2);
    ordered_insert(&list, node3);
    // ordered_insert(&list, node6);
    ordered_insert(&list, node5);

    delete(&list, node6);

    traverse_print(list);

}
