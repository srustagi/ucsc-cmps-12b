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
#define MAX_STRING_LENGTH 500

char* plural(int count);
void extract_chars(char* s, char* a, char* d, char* p, char* w);

int main(int argc, char* argv[]) {
	FILE* in;
	FILE* out;
	int line_number = 1;
	char* input;
	char* alpha;
	char* digit;
	char* punct;
	char* white;

	if (argc != 3) {
		printf("usage: %s <input file> <output file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	in = fopen(argv[1], "r");
	if (in == NULL) {
		printf("Unable to read from file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	out = fopen(argv[2], "w");
	if (out == NULL) {
		printf("Unable to write to file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	input = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	alpha = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	digit = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	punct = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	white = (char *) calloc(MAX_STRING_LENGTH + 1, sizeof(char) );
	assert( input != NULL && alpha != NULL && digit != NULL && punct != NULL && white != NULL );

	while (fgets(input, MAX_STRING_LENGTH, in) != NULL) {
		extract_chars(input, alpha, digit, punct, white);
		fprintf(out, "Line number %d contains:\n", line_number);
		fprintf(out, "%lu alphabetic %s: %s\n", strlen(alpha), plural(strlen(alpha)), alpha);
		fprintf(out, "%lu numeric %s: %s\n", strlen(digit), plural(strlen(digit)), digit);
		fprintf(out, "%lu punctuation %s: %s\n", strlen(punct), plural(strlen(punct)), punct);
		fprintf(out, "%lu whitespace %s: %s\n", strlen(white), plural(strlen(white)), white);
		line_number++;
	}

	free(input);
	free(alpha);
	free(digit);
	free(punct);
	free(white);

	fclose(in);
	fclose(out);

	return(EXIT_SUCCESS);
}

char* plural(int count) {
	if (count == 1) {
		return "character";
	} else {
		return "characters";
	}
}

void extract_chars(char* s, char* a, char* d, char* p, char* w) {
	int i = 0;
	int alpha_count = 0;
	int digit_count = 0;
	int punct_count = 0;
	int white_count = 0;

	while (s[i] != '\0' && i < MAX_STRING_LENGTH) {
		if ( isalpha( (int) s[i]) ) a[alpha_count++] = s[i];
		if ( isdigit( (int) s[i]) ) d[digit_count++] = s[i];
		if ( ispunct( (int) s[i]) ) p[punct_count++] = s[i];
		if ( isspace( (int) s[i]) ) w[white_count++] = s[i];
		i++;
	}

	a[alpha_count] = '\0';
	d[digit_count] = '\0';
	p[punct_count] = '\0';
	w[white_count] = '\0';
}