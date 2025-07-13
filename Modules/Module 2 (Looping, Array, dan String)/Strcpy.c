#include <stdio.h>
#include <string.h>

int main () {
  
	char a[] = "Halo";
	char b[10];
	
	// Copy string a ke string b
	strcpy(b, a);
	
	printf("%s\n", b);
	
	return 0;

}