/*  Google Code Jam I/O women 2017, problem A: Cody's Jam
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int price;
	struct node* next;
} Node;

int main()
{
    int T = 0, N = 0;
    Node** start;
	Node* counter, search_ptr;
    start = counter = search_ptr = NULL;
	int *num_array = NULL;

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);
    //printf("T = %d\n", T);

    for(int t = 1; t <= T; ++t){

        fscanf(fp, "%d", &N);
        num_array = (int *)calloc(2 * N, sizeof(int));
        for(int i = 0; i < 2 * N; ++i){
        	fscanf(fp, "%d", &num_arry[i]);
		}
        
		        
        printf("case #%d:\n", t);
    }
}
