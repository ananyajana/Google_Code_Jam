/*  Google Code Jam I/O women 2018, problem A
Author:Ananya Jana */

#include <stdio.h>
#include <stdlib.h>


#define PARENT(i)	((i - 1)/2)
#define LEFT(i)		(2*i + 1)
#define	RIGHT(i)	(2*i + 2)

void max_heapify(int a[], int i);
void build_max_heap(int a[]);
void heap_sort(int a[]);

//heap sz
int size, sz;

int main()
{
    int T, K, i, j, dist;
    T = K = i = dist = 0;
	int *arr = NULL;	// for the large dataset, a number can be of 10 digits, hence taking an array of long long integers

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){

        fscanf(fp, "%d", &K);
        // dynamically allocating an array of 2N elements and scanning the numbers from input file
        arr = (int *)calloc(2 * K, sizeof(int));
        for(i = 0; i < K; ++i){
        	fscanf(fp, "%d ", &arr[i]);
	}
	
	/*for(i = 0; i < K; ++i){
        	printf( "%d ", arr[i]);
	}*/
	
	dist = 0;
	
	size = sz = K;
	heap_sort(arr);
	/*for(i = 0; i < K; ++i){
        	printf( "%d ", arr[i]);
	}*/
	//printf("\n");
	
	if((K % 2) == 1){
		//printf("arr[%d] - %d\n", (K - 1), (K - 1)/2);
		dist += (arr[K-1] - ((K - 1)/2))*(arr[K-1] - ((K - 1)/2));
		//printf("dist = %d\n", dist);
	}

	K = K - 1;
	for(i = (K/2 - 1), j = (K - 1); i >= 0; --i, --j){
		//printf("arr[%d] - %d\n", j, i);
		//printf("dist = %d\n", dist);
		dist += (arr[j] - i)*(arr[j] - i);
		--j;
		//printf("arr[%d] - %d\n", j, i);
		dist += (arr[j] - i)*(arr[j] - i);
		//printf("dist = %d\n", dist);		
	}
	
	printf("Case #%d: %d\n", t, dist);
	if(arr)
		free(arr);
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