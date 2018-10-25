/*
 File: list_funcs.c
 Name: Shivansh Rustagi
 CruzID: 1651034
 Class: CMPS 12B
 Desc: A program which has utility and manipulation functions for a linked list implementation.
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * Function: *create_new_rider
 * Params:
 *      id: the ID for the user
 *      *first_name: the user's first name
 *      *last_name: the user's last name
 *      ave_rating: the user's average rating
 *      distance: the distance to the user
 * Return values:
 *      rider: pointer to a structure which has been placed in the computer's memory
 * Description:
 *      creates a new rider_st and allocates its memory with the given information inserted into the fields
 */
rider_st *create_new_rider(int id, char *first_name, char *last_name, double ave_rating, double distance) {
    // ask the OS for enough memory to store a "rider_st" structure
    rider_st *rider = (rider_st *) malloc(sizeof(rider_st));
    // fill out each of the fields of the structure in accordance with the provided values
    rider -> ID = id;
    rider -> first_name = first_name;
    rider -> last_name = last_name;
    rider -> ave_rating = ave_rating;
    rider -> distance = distance;
    // set next to null manually to ensure smooth sailing during all future manipulation
    rider -> next = NULL;
    // return a pointer to the newly created structure
    return rider;
}

/*
 * Function: front_insert
 * Params:
 *      **list_head: the address of the pointer of the head of the list, required so that not just a copy of the data is passed to the function
 *      *to_be_inserted: a pointer to the node which is to be inserted
 * Return values:
 *      None
 * Description:
 *      inserts the specified node into the front of the data structure
 */
void front_insert(rider_st **list_head, rider_st *to_be_inserted) {
    // deal with a null insertion attempt
    if ( to_be_inserted == NULL )
        return;
    // insert node if list is empty
    if ( *list_head == NULL ) {
        *list_head = to_be_inserted;
        // set the next field to NULL because to_be_inserted is the only item in the list
        to_be_inserted -> next = NULL;
    }
    // if the list is nonempty, insert node
    else {
        to_be_inserted -> next = *list_head;
        *list_head = to_be_inserted;
    }
}

/*
 * Function: end_insert
 * Params:
 *      **ptr_to_list_head: the address of the pointer of the head of the list, required so that not just a copy of the data is passed to the function
 *      *to_be_inserted: a pointer to the node which is to be inserted
 * Return values:
 *      None
 * Description:
 *      inserts the specified node into the back of the data structure
 */
void end_insert (rider_st **ptr_to_list_head, rider_st *to_be_inserted) {
    // initialize temporary pointer to cycle through the structure
    rider_st *temp;
    temp = *ptr_to_list_head;
    // deal with null insertion attempt
    if ( to_be_inserted == NULL )
        return;
    // just do a front insert if list is empty, since they're equivalent
    if ( temp == NULL ) {
        front_insert(ptr_to_list_head, to_be_inserted);
    }
    // if list is non-empty, cycle through the structure until the "current" node's next value is NULL, that is, the end of the list
    else {
        while ( temp -> next != NULL ) {
            temp = temp -> next;
        }
        // perform insertion, set the 'next' field to NULL as 'to_be_inserted' is now the end of the list
        temp -> next = to_be_inserted;
        to_be_inserted -> next = NULL;
    }
}

/*
 * Function: ordered_insert
 * Params:
 *      **ptr_to_list_head: the address of the pointer of the head of the list, required so that not just a copy of the data is passed to the function
 *      *to_be_inserted: a pointer to the node which is to be inserted
 * Return values:
 *      None
 * Conditions:
 *      Only works if the list has been created entirely with ordered_insert, as an out of order list does not work with this ORDERED insert. If the list is
 *      not ordered, the insert function simply inserts the node after the first node it is greater than.
 * Description:
 *      inserts the given node into the list based on the “distance” field ordering, least to greatest
 */
void ordered_insert (rider_st **ptr_to_list_head, rider_st *to_be_inserted) {
    // initialize temporary pointer to cycle through structure
    rider_st *temp;
    temp = *ptr_to_list_head;
    // deal with null insertion attempt
    if ( to_be_inserted == NULL )
        return;
    // if the list is empty, or 'to_be_inserted' is already the smallest value in the list, do a front insert
    if ( *ptr_to_list_head == NULL || temp -> distance >= to_be_inserted -> distance ) {
        to_be_inserted -> next = *ptr_to_list_head;
        *ptr_to_list_head = to_be_inserted;
    }
    // if 'to_be_inserted' is not the smallest value, cycle through the structure AS LONG AS the next value is not NULL
    // and the node reached is still smaller than 'to_be_inserted'
    else {
        while ( temp -> next != NULL && temp -> next -> distance < to_be_inserted -> distance ) {
            temp = temp -> next;
        }
        // upon reaching the correct node, insert 'to_be_inserted' into the list
        to_be_inserted -> next = temp -> next;
        temp -> next = to_be_inserted;
    }
}

/*
 * Function: empty
 * Params:
 *      *list_head: a pointer to the list head
 * Return values:
 *      None
 * Description:
 *      Deletes every element in the list and deallocates the space for each node.
 */
void empty (rider_st *list_head) {
    // delete the list head until there is nothing left to delete
    while ( list_head != NULL ) {
        // this works because delete() is written to handle a 'list_head' delete, see the function for more details
        delete(&list_head, list_head);
    }
}

/*
 * Function: delete
 * Params:
 *      **ptr_to_list_head: the address of the pointer to the list head
 *      *to_be_deleted: the node which is to be deleted
 * Return values:
 *      None
 * Description:
 *      Deletes the specified node from the structure
 */
void delete(rider_st **ptr_to_list_head, rider_st *to_be_deleted) {
    // initialize temporary variables for deletion
    rider_st *temp;
    rider_st *delete_temp;
    temp = *ptr_to_list_head;

    // case 1: empty list or null structure provided, don't do anything
    if ( temp == NULL || to_be_deleted == NULL )
        return;

    // case 2: head needs to be deleted
    if ( temp -> ID == to_be_deleted -> ID ) {
        // set 'delete_temp' to the list head so it can be freed
        delete_temp = temp;
        // set the list head pointer to the next node, since the head is going to be freed
        *ptr_to_list_head = temp -> next;
        // now that the structure is preserved and the list head pointer has been moved, free the original first node
        free(delete_temp);
    }

    // case 3: if the node is anywhere else
    // ensure that the next node is not NULL to prevent illegal memory access
    while ( temp -> next != NULL ) {
        // use temp next because the deletion will require access to the "previous" node from what is being deleted
        // in order to link the nodes on either side of the node which is targeted for deletion
        if ( temp -> next -> ID == to_be_deleted -> ID ) {
            // identify and temporary pointer to the node which is to be deleted
            delete_temp = temp -> next;
            // link the nodes on either side of the node which is going to be deleted
            temp -> next = temp -> next -> next;
            // delete the node
            free(delete_temp);
            return;
        }
        // if the current node is not the one to be deleted, move down the structure until it is
        temp = temp -> next;
    }
}

/*
 * Function: find_next_distance_rider
 * Params:
 *      *list_head: the pointer to the head of the list
 *      min_distance: the minimum distance specified
 * Return values:
 *      The node which is the next greatest from the min_distance
 * Description:
 *      returns the node that has the next greater distance value than the min_distance value passed. If there is no matching (greater distance)
 *      node found, a "null node" is returned to signify failure. This has been done because "NULL" cannot be returned.
 */
rider_st find_next_distance_rider( rider_st *list_head, double min_distance ) {
    // initialize temporary pointer to cycle through structure
    rider_st *temp;
    temp = list_head;
    // look through entire list for an appropriate node
    while ( temp != NULL ) {
        if ( temp -> distance <= min_distance ) {
            temp = temp -> next;
        } else if ( temp -> distance > min_distance ) {
            return ( *temp );
        }
    }
    // handle an empty list or failure to find any node greater than the specified 'min_distance'
    if ( temp == NULL ) {
        // since this function is of return type rider_st, return an empty rider_st to indicate failure
        return *create_new_rider(-1, "N/A", "N/A", -1, -1);
    }
}
