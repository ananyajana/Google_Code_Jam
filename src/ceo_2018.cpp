/*  Google Code Jam I/O women 2018, problem B
Author:Ananya Jana */

#include <stdio.h>
#include <stdlib.h>


#define PARENT(i)	((i - 1)/2)
#define LEFT(i)		(2*i + 1)
#define	RIGHT(i)	(2*i + 2)

void insertion_sort(int a[], int b[], int n);


int main()
{
    int T, L, E, N, i, j, min_exp, overflow, max;
    T = L = N = E = i = min_exp = overflow = 0;
	int *N_arr, *E_arr = NULL;	// for the large dataset, a number can be of 10 digits, hence taking an array of long long integers

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){

        fscanf(fp, "%d", &L);
        // dynamically allocating an array of 2N elements and scanning the numbers from input file
        N_arr = (int *)calloc(L, sizeof(int));
        E_arr = (int *)calloc(L, sizeof(int));
        
        for(i = 0; i < L; ++i){
        	fscanf(fp, "%d %d ", &N_arr[i], &E_arr[i]);
	}
	/*printf("original\n");
	for(i = 0; i < L; ++i){
        	printf( "%d ", N_arr[i]);
        	printf( "%d\n", E_arr[i]);
	}*/
	
	/*for(i = 0; i < K; ++i){
        	printf( "%d ", arr[i]);
	}*/
	
	min_exp = overflow = 0;
	
	//size = sz = K;
	//heap_sort(arr);
	insertion_sort(E_arr, N_arr, L);
	
	/*printf("after sorting\n");
	for(i = 0; i < L; ++i){
        	printf( "%d ", N_arr[i]);
        	printf( "%d\n", E_arr[i]);
	}*/
	
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
	
	printf("Case #%d: %d\n", t, min_exp);
	if(N_arr)
		free(N_arr);
	if(E_arr)
		free(E_arr);
    }
}


void insertion_sort(int a[], int b[], int n)
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