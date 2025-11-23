#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ptr;

int main(int argc, char *argv[])
{
	printf("Hello World!\n");
	ptr = malloc(20);
	strcpy(ptr, "Hello World");
	return 0;
}
