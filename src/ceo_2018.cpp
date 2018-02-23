/*  Google Code Jam I/O women 2018, problem B
Author:Ananya Jana */

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(long long int a[], long long int b[], long long int n);


int main()
{
    long long int T, L, E, N, i, j, min_exp, overflow, max;
    T = L = N = E = i = min_exp = overflow = 0;
	long long int *N_arr, *E_arr = NULL;	// for the large dataset, a number can be of 10 digits, hence taking an array of long long integers

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%lld", &T);

    for(int t = 1; t <= T; ++t){

        fscanf(fp, "%lld", &L);
        // dynamically allocating an array of 2N elements and scanning the numbers from input file
        N_arr = (long long int *)calloc(L, sizeof(long long int));
        E_arr = (long long int *)calloc(L, sizeof(long long int));
        
        for(i = 0; i < L; ++i){
        	fscanf(fp, "%lld %lld ", &N_arr[i], &E_arr[i]);
	}
	
	min_exp = overflow = 0;
	
	insertion_sort(E_arr, N_arr, L);
	
	if(L == 1){
		if(N_arr[0] > E_arr[0])
			min_exp = N_arr[0];
		else
			min_exp = E_arr[0] + 1;
	}
	else{
		for(i = 1; i < L; ++ i){
			overflow = (N_arr[i - 1] + overflow) - (N_arr[i] * E_arr[i]);
			if(overflow < 0)
				overflow = 0;
		}

		/*max = (E_arr[L - 1] > N_arr[L - 1]) ? E_arr[L - 1] : N_arr[L - 1];
		if(overflow > 0)
			min_exp = max + overflow;
		else
			min_exp = max + 1;*/
		if(E_arr[L - 1] >= (N_arr[L - 1] + overflow))
			min_exp = E_arr[L - 1] + 1;
		else
			min_exp = N_arr[L - 1] + overflow;
	}
	
	printf("Case #%d: %lld\n", t, min_exp);
	if(N_arr)
		free(N_arr);
	if(E_arr)
		free(E_arr);
    }
}


void insertion_sort(long long int a[], long long int b[], long long int n)
{
	int i, j, key;

	for(j = 1; j < n; ++j){
		key = a[j];
		i = j - 1;
		while(i >= 0 && a[i] > key){
			a[i + 1] = a[i];
			b[i + 1] = b[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
}