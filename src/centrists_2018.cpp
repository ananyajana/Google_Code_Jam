/*  Google Code Jam I/O women 2018, problem C
Author:Ananya Jana */

#include <stdio.h>
#include <stdlib.h>



int main()
{
    int T, L, E, N, i, j;
    T = L = N = E = i = 0;
	int *name1, *name2, *name3;	// We want to scan the three names of length L
	int flag[3] = {0, 0, 0};	// a boolean array to keep track whether the name can appear in the middle

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){

        fscanf(fp, "%d", &L);
        // dynamically allocating the space for the three names
        name1 = (int *)calloc((L + 1), sizeof(int));
        name2 = (int *)calloc((L + 1), sizeof(int));
        name3 = (int *)calloc((L + 1), sizeof(int));
        
        if(!name1 || !name2 || !name3)
        	exit(1);
        	   
        fscanf(fp, "%s %s %s", &name1, &name2, &name3);
	
	


	
	printf("Case #%d: ", t);
	// traversing the boolean array to check whether the ith name can appear in the middle
	for(i = 0; i < 3; ++i){
		if(flag[i])
			printf("yes ");
		else
			printf("no ");
	}
	printf("\n");
	
	if(name1)
		free(name1);
	if(name2)
		free(name2);
	if(name3)
		free(name3);
    }
}
