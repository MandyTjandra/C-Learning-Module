#include <stdio.h>

int main () 
{
	int a[5] = {1,2,3,4,5}, i; 
	for(i = 0; i < 5; i++) {
		scanf("%d", &a[i]); //Input array
	}

	for(i = 0; i < 5; i++) {
		printf("Bilangan ke-%d adalah %d\n", i+1, a[i]); // Output array
	}

	return 0;

}