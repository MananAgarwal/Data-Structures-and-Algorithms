#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	printf("\nNumber of arguments = %d", argc);
	for(int i=0;i<argc;i++) {		
		for(int j=0; j<strlen(argv[i]); j++)
		{ if(isdigit(argv[i][j])) 
			{
			printf("%d",atoi(argv[i]));
			break;
			}
		}
	}
}
