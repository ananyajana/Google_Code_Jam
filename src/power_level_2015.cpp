/*  Google Code Jam I/O women 2015, problem C: Power Levels
Solution:
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
        int T=0, D=0, i, num_factorial, current_num = 0;
        double temp = 0;
        double log_values[9000] = {0};	// taking an array to contain the log (to base 10) value of all the numbers from 1 to 9000, so that we need not calculate everytime
        double digit_arr[9000] = {0};	// taking an array to contain the number of digits in the multifactorials of 9000 

        FILE* fp = fopen("ip.txt", "r");
        if(NULL == fp)
                exit(1);

		// scan the number of testcases
        fscanf(fp, "%d\n", &T);

		// pre-calculating the log values
		for(i = 1; i <= 9000; ++i)		
			log_values[i] = log(i);
		
		// pre-storing the number of digits in a multifactorial of 9000 in an array
		current_num = 9000;
		for(num_factorial = 1; num_factorial <= 9000; ++num_factorial){
			while((current_num - num_factorial) > 0){
				digit_arr[num_factorial] += log(current_num);
				current_num -= num_factorial;
			}
			temp = ceil(digit_arr[num_factorial]);
			digit_arr[num_factorial] = (int)temp;
 		}
			
		
        for(int t = 1; t <= T; ++t){
        		//scan the number of digits in the opponent's number
                fscanf(fp, "%d", &D);
            
                
                printf("Case #%d: %llu\n", t);
        }
}

				
		
		
