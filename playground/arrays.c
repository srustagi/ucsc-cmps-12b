#include <stdio.h>
#define MAX 5         
/* no magic numbers, get used to defining them as constants */

int main(){
	
	int an_array[10];     /* declare the array of ints, MAX of them, remember C index starts at 0 */
	int i;                /* index variable */
	int *location;        /* the address of an integer */

	/* this should really be done as an iteration, but for a quick demo OK */
	an_array[0] = 100;
	an_array[1] = 101;
	an_array[2] = 202;
	an_array[3] = 303;
	an_array[4] = 404;
	an_array[5] = 505;

	printf ("Welcome an array walk through with a pointer access to array elements!\n\n");
	printf ("walk through the array %d times\n\n", MAX);
	
	for (i=0; i <= MAX; i++) {
		location =  &an_array[i];
		printf("element [%d] contents =  %d \n", i, an_array[i] );
		printf ("contents by pointer access %d\n", *location);
		printf ("array element location %p \n\n",  location);
	}

	return 0; /* all is well  in UNIX */
}