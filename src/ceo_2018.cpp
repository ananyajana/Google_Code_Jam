/*  Google Code Jam I/O women 2018, problem B
Author:Ananya Jana */

#include <stdio.h>
#include <stdlib.h>


#define PARENT(i)	((i - 1)/2)
#define LEFT(i)		(2*i + 1)
#define	RIGHT(i)	(2*i + 2)

void insertion_sort(int a[], int b[], int n);

void max_heapify(int a[], int i);
void build_max_heap(int a[]);
void heap_sort(int a[]);

//heap sz
int size, sz;

int main()
{
    int T, L, E, N, i, j, min_exp, overflow;
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
			overflow = (N_arr[i] * E_arr[i]) - (N_arr[i - 1] + overflow); 
		}
		if((overflow + N_arr[L - 1]) > E_arr[L - 1])
			min_exp = E_arr[L - 1] + overflow + N_arr[L - 1];
		else
			min_exp = E_arr[L - 1] + 1;
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

void build_max_heap(int a[])
{
	int i;
	for(i = (sz - 1)/2; i >= 0; --i){
		//printf("i = %d\n", i);
		max_heapify(a, i);
	}	
}

void max_heapify(int a[], int i)
{
	int l, r, largest, temp;
	l = LEFT(i);
	r = RIGHT(i);

	//printf("%d %d\n", a[i], i);	
		
	if((l < sz) && (a[l] > a[i]))
		largest = l;
	else
		largest = i;
	if((r < sz) && ( a[r] > a[largest]))
		largest = r;
	if(largest != i){
		temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		/*printf("hi\n");
		for(i = 0; i < size; ++i){
			printf("%d ", a[i]);
		}
		printf("\n");*/
		max_heapify(a, largest);
	}	
}

void heap_sort(int a[])
{
	int i, temp;
	
	build_max_heap(a);
	//printf("The heap is\n");
	/*for(i = 0; i < size; ++i){
		printf("%d ", a[i]);
	}*/
	//printf("\n");
	
	//place the biggest element which is at the root, at the end of the array
	for(i = sz - 1; (i >= 1) && (sz > 1); --i){
		//printf("1.sz = %d, i = %d\n", sz, i);
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;

		/*printf("hi1\n");
		for(i = 0; i < size; ++i){
			printf("%d ", a[i]);
		}
		printf("\n");*/
		//reduce the size of the heap as we removed the largest element
		--sz;
	
		//create a heap out of the remaining elements in the heap
		max_heapify(a, 0);
		//printf("2.sz = %d, i = %d\n", sz, i);
	}
}