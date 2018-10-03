#include<stdio.h>
int main(){
	// printf("hello, world");
	int a[] = {7,8};
	for(int i = 0; i < 2; i++){
		printf("%d ", a[i]);
		printf("%p\n", &a[i]);
	}
}