/* Author:Ananya Jana */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T=0, B=0, D=0, i, j;
    unsigned long long* D_arr = NULL;
    

	FILE* fp = fopen("ip.txt", "r");
	
	fscanf(fp, "%d", &T);
	printf("T = %d\n", T);	
	
	for(int t = 1; t <= T; ++t){
        fscanf(fp, "%d", &B);   
	    printf("B = %d\n", B);	
        D_arr = (unsigned  long long)calloc(B, sizeof(unsigned long long));
        for(i = 0; i < B; ++i)
            for(j = 0; j < i; ++j)
                fscanf(fp, "%llu", &D_arr[i][j]);

		printf("Case #%d: %s\n", t, D);
	}
}
				
		
		
