/*  Google Code Jam I/O women 2014, problem A: Saturnalia

Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAXLEN	70


int main()
{
	int N, T, len, i;
	N = T = len = 0;
	char arr[MAXLEN + 1];
	
	FILE* fp = fopen("ip.txt", "r");
	
	// if the file is not valid, exit
	if(NULL == fp){
		printf("Error, Can't open file");
		exit(1);
	}
	
	fscanf(fp, "%d", &T);
	
	for(int t = 1; t <= T; ++t){
    		fscanf(fp, "%s", &arr); // scanning the strings one by one
    		len = strlen(arr);
    		printf("Case #%d:\n", t);
    		printf("+");
    		for(i = 1; i <= len + 2; ++i)
    			printf("-");
    		printf("+\n| %s |\n+", arr);
    		for(i = 1; i <= len + 2; ++i)
    			printf("-");
    		printf("+\n");
	}
}
