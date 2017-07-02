/*  Google Code Jam 2017, problem B: Tidy Numbers
Check if the number is already a tidy number, if not
get to the biggest tidy number by processing from the
right side. At any time, take two contiguous digits and
transform them to be tidy. Then move to the left and again
process the two contiguous digits.
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int T = 0, input = 0, num = 0, digit_current = 9, digit_prev = 9, res = 0, count = 0;	//num contains the biggest tidy number, input is the input number
    bool flag = true;		// flag to check if the number is tidy
	
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
    	digit_current = digit_prev = 9;	// initializing the values
    	count = 0;	// count of the number of digits in the number
    	
    	while(res){
    		digit_prev = digit_current;
    		digit_current = res % 10;
    		//printf("digit_prev = %d, digit_current = %d\n", digit_prev, digit_current);
    		if(digit_current > digit_prev)
    			flag = false;
    		res = res / 10;
    		count++;
		}
		if(false == flag)
			printf("Not a tidy number.\n");
		else
			printf("Tidy number.\n");
		printf("Number of digits = %d\n", count);
	}
}
