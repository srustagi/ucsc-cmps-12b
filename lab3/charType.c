/*
 File: charType.c
 Name: Shivansh Rustagi
 CruzID: 1651034
 Class: CMPS 12M
 Desc: A program which reads characters from a file, and determines how many characters of each type there are in the file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 500   // this file ONLY works if there are 500 or fewer characters per line, I was not able to dynamically set this number
// nor come up with a suitable algorithm which wouldn't fail with scale.

/*
 * plural function prototype
 * description: determine whether the output should say "character" or "characters" depending on the number of chars
 * params:
 * 	int count --> the number of particular subset of characters
 */
char* plural(int count);

/*
 * extract_chars function prototype
 * description: extract different subsets of characters from a string
 * params:
 * 	char* s --> the string from which to extract chars
 * 	char* a --> the string which, after the method is done, contains all the alphabetic characters
 * 	char* d --> the string which, after the method is done, contains all the numeric characters
 * 	char* p --> the string which, after the method is done, contains all the punctuation characters
 * 	char* w --> the string which, after the method is done, contains all the whitespace characters
 */
void extract_chars(char* s, char* a, char* d, char* p, char* w);

int main(int argc, char* argv[]) {
	FILE* in;                    // input file
	FILE* out;                   // output file
	int line_number = 1;         // keep track of line numbers as fgetc progresses through the file
	char* input;                 // the string which contains input from the field
	char* alpha;                 // the string which contains alphabetic characters
	char* digit;                 // the string which contains numeric characters
	char* punct;                 // the string which contains punctuation characters
	char* white;                 // the string which contains whitespace characters

	// check for correct program usage
	if (argc != 3) {
		printf("usage: %s <input file> <output file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// open file for reading
	in = fopen(argv[1], "r");
	// check if file can actually be read, if not exit with failure
	if (in == NULL) {
		printf("Unable to read from file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// open file for writing
	out = fopen(argv[2], "w");
	// check if file can be written to, if not exit with failure
	if (out == NULL) {
		printf("Unable to write to file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	// set memory dynamically for both the input line and each individual subset line
	input = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	alpha = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	digit = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	punct = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	white = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	// ensure that memory allocation was completed successfully
	assert( input != NULL && alpha != NULL && digit != NULL && punct != NULL && white != NULL );

	// while loop which uses fgets(), traversing through input line by line and separating out each subset of characters.
	while (fgets(input, MAX_STRING_LENGTH, in) != NULL) {
		extract_chars(input, alpha, digit, punct, white);
		// print data TO FILE once extracted
		fprintf(out, "Line number %d contains:\n", line_number);
		fprintf(out, "%lu alphabetic %s: %s\n", strlen(alpha), plural(strlen(alpha)), alpha);
		fprintf(out, "%lu numeric %s: %s\n", strlen(digit), plural(strlen(digit)), digit);
		fprintf(out, "%lu punctuation %s: %s\n", strlen(punct), plural(strlen(punct)), punct);
		fprintf(out, "%lu whitespace %s: %s\n", strlen(white), plural(strlen(white)), white);
		// increment line number for next iteration of while loop
		line_number++;
	}

	// close files once reading and writing are done
	fclose(in);
	fclose(out);

	// free all allocated memory
	free(input);
	free(alpha);
	free(digit);
	free(punct);
	free(white);

	// all is well!
	return (EXIT_SUCCESS);
}

// quick method to make determining "characters" vs "character" less complicated and shorter
char* plural(int count) {
	// if the amount of characters in the subset is only 1, return 'character' otherwise return 'characters'
	if (count == 1) {
		return "character";
	} else {
		return "characters";
	}
}

// see prototypes
void extract_chars(char* s, char* a, char* d, char* p, char* w) {
	// index variable for loop as well as counts for each individual subset, used later to insert null terminator
	int i = 0;
	int alpha_count = 0;
	int digit_count = 0;
	int punct_count = 0;
	int white_count = 0;

	// while not at the end of the string and not having have surpassed the max string length, continue with the body
	while (s[i] != '\0' && i < MAX_STRING_LENGTH) {
		// pick out which of the different subsets the character belongs to and increment its count while storing it in the appropriate character's array
		if ( isalpha( (int) s[i]) ) a[alpha_count++] = s[i];
		if ( isdigit( (int) s[i]) ) d[digit_count++] = s[i];
		if ( ispunct( (int) s[i]) ) p[punct_count++] = s[i];
		if ( isspace( (int) s[i]) ) w[white_count++] = s[i];
		// increment loop variable to get next character from input string
		i++;
	}

	// terminate all subsets' strings with null terminator to indicate end of string
	a[alpha_count] = '\0';
	d[digit_count] = '\0';
	p[punct_count] = '\0';
	w[white_count] = '\0';
}
