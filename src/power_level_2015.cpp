/*  Google Code Jam I/O women 2015, problem C: Power Levels
Solution:
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main()
{
    int T=0, D = 0, i, j, num_factorial, current_num = 0;
    double temp = 0, temp1 = 0;
    double log_values[9001] = {0};	// taking an array to contain the log (to base 10) value of all the numbers from 1 to 9000, so that we need not calculate everytime
    double digit_arr[9001] = {0};	// taking an array to contain the number of digits in the multifactorials of 9000 

    FILE* fp = fopen("ip.txt", "r");
    if(NULL == fp)
            exit(1);

	// scan the number of testcases
    fscanf(fp, "%d\n", &T);

	// pre-calculating the log values
	for(i = 1; i <= 9000; ++i){
		log_values[i] = log10(i);
	}		
		
	
	// pre-storing the number of digits in a multifactorial of 9000 in an array
	for(num_factorial = 1; num_factorial <= 9000; ++num_factorial){
		temp = 0;
		current_num = 9000;
		while(current_num > 0){
			temp += log_values[current_num];
			current_num -= num_factorial;
		}
		digit_arr[num_factorial] = ceil(temp);
	}
		
    for(int t = 1; t <= T; ++t){
    	//scan the number of digits in the opponent's number
        fscanf(fp, "%ld", &D);
    	
        if(D <= 4){	// if the number of digits is 4 or less, then Anima would be silent
        	printf("Case #%d: ...\n", t);
        }
        else{
        	char* print_string = NULL;
        	num_factorial = 9000;
        	while((D > digit_arr[num_factorial]) && (num_factorial > 0))	// iterate from the end of the digit_arr until we get an element  >= D
        		--num_factorial;
        	++num_factorial;
        	
        	print_string = (char*)calloc((num_factorial + 1), sizeof(char));	//allocate a temporary character array to hold the number of !s
			memset(print_string, '!', num_factorial);
			printf("Case #%d: IT'S OVER 9000", t);
			printf("%s\n", &print_string[0]);	// append the temporary string to the output 
			free(print_string);
		}			
    }
}

				
		
		
