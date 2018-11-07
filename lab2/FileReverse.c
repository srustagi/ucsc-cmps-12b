/*
 File: FileReverse.c
 Name: Shivansh Rustagi
 CruzID: 1651034
 Class: CMPS 12M
 Desc: A program which reads words from a file, and writes them to another file, reversed, one per line.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * stringReverse function prototype
 * params:
 *    char* s: the string to be reversed
 */
void stringReverse(char* s);

int main(int argc, char* argv[]) {
	FILE* in;     // input file initialization
	FILE* out;    // output file initialization
	char *word;   // string initialization

	// error handling for incorrect run of program
	if (argc != 3) {
		printf("Usage: %s <input file> <output file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// open the input file for reading
	in = fopen(argv[1], "r");
	// error handling for if contents of file are null
	if (in == NULL) {
		printf("Unable to read from file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// malloc utilizes dynamic memory, as the size of the file is unknown
	// once file has been read, assign its contents to the string "word" in preparation for reversal/further manipulation
	word = (char *) malloc(sizeof(in));

	// create output file and prepare for writing
	out = fopen(argv[2], "w");
	// output file error handling
	if (out == NULL) {
		printf("Unable to write to file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	// formatted read from file as long as there is data to read
	// reverse each word and print on new line
	while ( fscanf(in, " %s", word) != EOF ) {
		stringReverse(word);
		fprintf(out, "%s\n", word);
	}

	// close files, free memory allocated to word as program is finished
	fclose(in);
	fclose(out);
	free(word);

	// all is well!
	return (EXIT_SUCCESS);
}

// see function prototype for details
void stringReverse(char* s) {
	// initialize two index variables and a temp char used to swap
	int i = 0;
	int j = strlen(s) - 1;
	char temp;

	// start at both ends of the string and swap characters until the two indexes meet, and then stop.
	while (i < j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		// increment i and decrement j to move on to the next swap
		i++;
		j--;
	}
}
