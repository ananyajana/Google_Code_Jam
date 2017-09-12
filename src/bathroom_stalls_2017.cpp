/*  Google Code Jam 2017, problem C: Bathroom Stalls
Looks like divide and conquer mechanism ha to be applied.
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX	4

int main()
{
	int N, K;
	N = K = 0;
	
	FILE* fp = fopen("ip.txt", "r");
	
	// if the file is not valid, exit
	if(NULL == fp){
		printf("Error, Can't open file");
		exit(1);
	}
	
    fscanf(fp, "%d", &T);
	
    for(int t = 1; t <= T; ++t){
    	fscanf(fp, "%d %d", &N, &K); // scanning the number of bathrooms and the number of people who will enter one by one
    	
    	
	}
}
