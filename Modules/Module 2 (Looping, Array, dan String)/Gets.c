#include <stdio.h>
#include <stdbool.h>

int main () {
  
	char arr[100];
	while(true)
	{
		gets(arr); /*gets() is unsafe and has been removed from the C standard. It's better to use fgets() to avoid buffer overflow problems.*/	
		printf("-- %s\n", arr);
	}
  return 0;

}