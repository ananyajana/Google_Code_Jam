/*  Google Code Jam 2017, problem A: Oversized Pancake flipper
We will try to minimize the distance between the first and last
sad face. We can do this by traversing the entire string and 
flipping when a sad face is found. In this way we will reach
a situation where all the sad faces will be contiguous. If the
number of sad faces % K != 0, then it is impossible to have all
happy faces. Else all the sad faces will be eventually turned
into happy face.
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE	10

int main()
{
    int T = 0, K = 0, i = 0, len = 0;	//K is the size of the pancake flipper. 2 <= K <= S
    char *str = NULL;
	
	FILE* fp = fopen("ip.txt", "r");
	
	// if the file is not valid, exit
	if(NULL == fp){
		printf("Error, Can't open file");
		exit(1);
	}
	
    fscanf(fp, "%d", &T);

	str = (char*)calloc(SIZE+1, sizeof(char));
	str[10] = '\0';
    for(int t = 1; t <= T; ++t){
		fscanf(fp, "%s ", str);		//scan the string of happy faces and sad faces
		fscanf(fp, "%d", &K);		// scan the size/capacity of the ladle
		
		len = strlen(str);			// find the length of the string of happy faces and sad faces
		//printf("length is : %d\n", len);
		
		memset(str, 0, len);	// clear the dynamically created array so that it can be used to hold the next string
	}
	
	if(str)		// if the dynamically allocated array to hold the string exists, delete it
		free(str);
}
