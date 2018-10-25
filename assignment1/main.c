#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_node(rider_st rider);
void print_struct(rider_st *list_head);

int main(void) {
	rider_st *shiv = create_new_rider(1, "Shiv", "Rustagi", 5.0, 0.01);
	rider_st *soma = create_new_rider(2, "Soma", "Badhri", 5.0, 0.02);
	rider_st *kamil = create_new_rider(3, "Kamil", "Polish", 5.0, 0.03);
	rider_st *george = create_new_rider(4, "nibba", "Mario", 5.0, 0.04);
	rider_st *rachel = create_new_rider(5, "nmobber", "OwO", 5.0, 0.05);
	rider_st *nibba = create_new_rider(6, "mob boss", "UwU", 5.0, 0.06);

	rider_st *list_head = NULL;
	rider_st *temptemp = NULL;
	ordered_insert(&list_head, rachel);
	ordered_insert(&list_head, nibba);
	ordered_insert(&list_head, soma);
	ordered_insert(&list_head, shiv);
	ordered_insert(&list_head, kamil);
	ordered_insert(&list_head, george);
	delete(&list_head, kamil);
	delete(&list_head, nibba);
	delete(&list_head, soma);
	delete(&list_head, shiv);
	delete(&list_head, george);
	delete(&list_head, list_head);
	// empty(list_head);
	// list_head = NULL;
	// ordered_insert(&list_head, george);
	print_struct(list_head);
	// print_node(find_next_distance_rider(temptemp, 0.001));
	return EXIT_SUCCESS;
}

void print_node(rider_st rider) {
	printf("Location: %p, ID: %d, Name: %s %s, Distance: %f\n", &rider, rider.ID, rider.first_name, rider.last_name, rider.distance);
}

void print_struct(rider_st *list_head) {
	rider_st *temp;
	temp = list_head;
	while ( temp != NULL ) {
		print_node( *temp );
		temp = temp -> next;
	}
}
