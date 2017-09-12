/*  Google Code Jam 2017, problem C: Bathroom Stalls
Looks like divide and conquer mechanism ha to be applied.
Probably gaps should be in sorted order, so that we don't
need to process all gaps. Only the lasrgest gap(s) at any
time are processed. Rest need not be processed.
We do not need to process all the cells in a gap. We have to
process only the middle cell(s).
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
