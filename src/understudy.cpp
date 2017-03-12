#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T=0, N=0;
	float* P_arr = '\0';
	float temp;
	int t = 0, k = 0, f = 0;
	long double probability = 1, both_absent = 0;

	FILE* fp = fopen("ip.txt", "r");
	
	fscanf(fp, "%d", &T);
	//printf("T = %d\n", T);	
	
	for(t = 1; t <= T; ++t){
		N = 0;
		probability = 1;

		fscanf(fp, "%d", &N);
		//printf("F = %d S = %d\n", F, S);
		P_arr = (float *) calloc(N * 2, sizeof(float));
		fscanf(fp, "%f", &P_arr[0]);	

		for(f = 1; f < 2 * N; ++f){
			fscanf(fp, "%f", &P_arr[f]);	
			for(k = 0; k < f; ++k){
				if(P_arr[k] > P_arr[f])
					break;
				
			}
			if(k != f){
				temp = P_arr[f];
				for(int j = f; j > k; --j){
					P_arr[j] = P_arr[j - 1];
				}
				P_arr[k] = temp;
			}
		}

	 	for(f = 0; f < N; ++f){
			both_absent = (long double)P_arr[f] * (long double)P_arr[2 * N - 1 -f];
			probability *= (1 - both_absent);
		}
		free(P_arr);
		printf("Case #%d: %Lf\n", t, probability);
	}
}
				
		
		
