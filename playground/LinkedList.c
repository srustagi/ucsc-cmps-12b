#include <stdio.h>
#include <stdlib.h>

*int gay(int);

int main()
{
	int gay_int = *gay(7);
	printf("%d", gay_int);
}

& gay(int a){
	return &a;
}