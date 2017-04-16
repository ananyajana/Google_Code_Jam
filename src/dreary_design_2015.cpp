#include <stdio.h>
#include <stdlib.h>

int main()
{
        unsigned long long int T=0, K=0, V=0, i, j, total=0;

        FILE* fp = fopen("ip.txt", "r");
        if(NULL == fp)
                exit(1);

		// scan the number of testcases
        fscanf(fp, "%d\n", &T);


        for(int t = 1; t <= T; ++t){
        		//scan the number of color levels and the max permissible difference in color levels to be bland
                fscanf(fp, "%llu %llu", &K, &V);
                if(0 == V)
                	total = K + 1;
                else
                	total = 3 * (V + 1) * (V + 1) * (K - V + 1) + ((V * (V + 1) * ( 2 * V + 1)) / 2)  - 2;
                	//total = K + 1 + (V * (V + 1) * (3 * K - 2 * V + 2));
                
                printf("Case #%d: %llu\n", t, total);
        }
}

				
		
		
