/*  Google Code Jam 2017, problem B: Tidy Numbers
Check if the number is already a tidy number, if not
get to the biggest tidy number by processing from the
right side. At any time, take two contiguous digits and
transform them to be tidy. Then move to the left and again
process the two contiguous digits. We need to keep track
of the maximum digit as well, else the above login won't work
for numbers like 1000.
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX	4

int main()
{
    int T, input, num, digit_current = 9, digit_prev = 9, res, count, i, k, j, max;	//num contains the biggest tidy number, input is the input number
    T = num = res = count = i = k = j = max = 0
    bool flag = true, carry = false;		// flag is to check if the number is tidy, carry is to check whether the digit to the left of current digit is impacted
    int digit[MAX];		// the number of digits can be maximum 4 in case of small input and 19 in case of large input
	
	FILE* fp = fopen("ip.txt", "r");
	
	// if the file is not valid, exit
	if(NULL == fp){
		printf("Error, Can't open file");
		exit(1);
	}
	
    fscanf(fp, "%d", &T);
	
    for(int t = 1; t <= T; ++t){
    	fscanf(fp, "%d", &input);
    	
    	//check if the input number is tidy
    	res = input;
    	flag = true;
    	carry = false;
    	digit_current = digit_prev = 9;	// initializing the values
    	count = 0;	// count of the number of digits in the number
    	i  = k = 0;		// iterator for the digits array needs to be initialized to 0 for every input
    	
    	while(res){
    		digit_prev = digit_current;
    		digit_current = res % 10;
    		//printf("digit_prev = %d, digit_current = %d\n", digit_prev, digit_current);
    		if(digit_current > digit_prev)
    			flag = false;
    		res = res / 10;
    		count++;
    		digit[i] = digit_current;
    		i++;
		}
		if(false == flag){
			//printf("Not a tidy number.\n");

			//printf("Number of digits = %d\n", count);
			
			for(k = 0; k < i ; ++k){
				if(true == carry){
					if(digit[k] == 0){
						digit[k] = 9;					
					}
					else{
						digit[k] = digit[k] - 1;
						carry = false;
					}
				}
				if(digit[k] == 0){
					digit[k] = 9;
					carry = true;
				}
				else if(digit[k] < digit[k + 1]){
					digit[k] = 9;
					carry = true;
				}
			}
			
			printf("Case #%d: ", t);
			while(i--){
				printf("%d",  digit[i]);
			}
			printf("\n");
		}
		else
			printf("Case #%d: %d\n", t, input);
	}
}
