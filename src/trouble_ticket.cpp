/* Author:Ananya Jana */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T=0, F=0, S=0, max = 0;
	int* S_arr = '\0';
	int* F_arr = '\0';
	int ai = 0, bj = 0;

	FILE* fp = fopen("ip.txt", "r");
	
	fscanf(fp, "%d", &T);
	//printf("T = %d\n", T);	
	
	for(int t = 1; t <= T; ++t){
		F = S = max = 0;

		fscanf(fp, "%d %d", &F, &S);
		//printf("F = %d S = %d\n", F, S);
		S_arr = (int *) calloc((S+1), sizeof(int));
		F_arr = (int *) calloc(((2 * F)+1), sizeof(int));
		for(int f = 0; f < F; ++f){
			fscanf(fp, "%d %d", &ai, &bj);	
			F_arr[2 * f] = ai;
			F_arr[2 * f + 1] = bj;

			//printf("f = %d\n", f);
			//printf("ai = %d bj = %d\n", ai, bj);
		
			if(ai == bj){
				++S_arr[ai];
				//printf("S_arr[%d] = %d\n", ai, S_arr[ai]);
			}
			else if(f == 0){
					++S_arr[ai];
					++S_arr[bj];
					//printf("S_arr[%d] = %d\n", ai, S_arr[ai]);
					//printf("S_arr[%d] = %d\n", bj, S_arr[bj]);
			}				
			else{
				int found = 0;
				for(int k = 0; k < f; ++k){
					if((F_arr[2 * k] == ai ) && (F_arr[2 * k + 1] == bj))
						found = 1;
				}
				if(!found){
					++S_arr[ai];
					++S_arr[bj];
					//printf("S_arr[%d] = %d\n", ai, S_arr[ai]);
					//printf("S_arr[%d] = %d\n", bj, S_arr[bj]);
				}
			}
			if((max < S_arr[ai] ) || (max < S_arr[bj])){
				//printf("max = %d\n", max);
				if(S_arr[ai] < S_arr[bj])
					max = S_arr[bj];
				else
					max = S_arr[ai];
			}
			//printf("max = %d\n", max);
		}
		free(S_arr);
		free(F_arr);
		printf("Case #%d: %d\n", t, max);
	}
}
				
		
		
