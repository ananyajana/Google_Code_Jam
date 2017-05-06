/*  Google Code Jam I/O women 2017, problem A: Cody's Jam
The least element at each step is a sale price, and hence
we can search for the corresponding actual price of the item
in the array and erase that element. In this way, we will
end up with only the sale prices in the array.
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int T, N, i, j, min_price, actual_price;
    T = N = i = j = 0;
	long long int *num_array = NULL;	// for the large dataset, a number can be of 10 digits, hence taking an array of long long integers

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){

        fscanf(fp, "%d", &N);
        // dynamically allocating an array of 2N elements and scanning the numbers from input file
        num_array = (long long int *)calloc(2 * N, sizeof(long long int));
        for(i = 0; i < 2 * N; ++i){
        	fscanf(fp, "%lld", &num_array[i]);
		}
		
		printf("Case #%d:", t);
		// at each step, we start from the currently non-zero smallest element and iterating over the entire array to see which index has the element value = actual price
		for(i = 0; i < 2 * N; ++i){
			if(0 != num_array[i]){	// the min_price must be non-zero		
				min_price = num_array[i];
				printf(" %lld", min_price);
				actual_price = 	(min_price / 3) * 4;	// since actual price is 4/3 of the minimum price

				for(j = i+1; j < 2 * N; ++j){	// search for the index where we get the actual price and erase that 
					if(num_array[j] == actual_price){
						num_array[j] = 0;
						break;
					}
				}
			}
			else		//if the element is zero, that means it contained actual price and thus has been deleted from this array, so skip this element
				continue;
		}
        printf("\n");

		if(num_array)
			free(num_array);
    }
}
