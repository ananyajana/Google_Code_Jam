/* A colour is represented as (R, G, B). We calculate the number of possible bland colours when the minimum
colour level is given. We deduce that in the following way:

when the minimum colour level is present in only one of the three fields, the other two fields can be filled 
with any one of the values in the range( minimum colour level + 1, minimum colour level + V). Thus V possibilities
for each of the other two fields, hence a total of V * V possibilities total for the two fields. Now, if the minimum
level is present at R position, then we have V * V possibilities. Similarly if the minimum colour level is present at
G position, then we have V * V possibilities and so for position B. Hence we have a total of 3 * V * V possibilities.

When the minimum colour level is present in two of the three positions, then we have total V possibilities for the
remaining position. Again, this remaining position could be any of R, G or B. Hence total 3 * V possibilities.

When the minimum colour level is present in three fields, then we have only 1 possibility.

We can start counting in this way by making the minimum colour level as 0, 1 and so on upto (K - V). So, total
number of possibilities = K - V + 1(since we started counting from 0).

When the minimum colour level = K - V + 1, we notice that the number of possible values for the other fields reduces to V - 1
The total can be calculated again using the method used above, by replacing V with V - 1.
Similarly for minimum colour level = K - V + 2, the number of possible values for the other fields = V - 2
Total = combinations with minimum colour level as 0 + 
		combinations with minimum colour level as 1 + 
		.
		.
		.
		combinations with minimum colour level as (K - V) +
		combinations with minimum colour level as (K - V + 1) +
		.
		.
		.
		combinations with minimum colour level as K
		 = [ 3 * V * V + 3 * V + 1 ] +
		   [ 3 * V * V + 3 * V + 1 ] + 
		   .
		   .
		   .
		   [ 3 * V * V + 3 * V + 1 ] +
		   [ 3 * (V  - 1)* (V - 1) + 3 * (V - 1) + 1 ] +
		   [ 3 * (V  - 2)* (V - 2) + 3 * (V - 2) + 1 ] +
		   .
		   .
		   .
		   [ 3 * 1* 1 + 3 * 1 + 1 ]
		   = [{(3 * V * V + 3 * V + 1)(K - V + 1)} + {(V - 1) * V * (2 * V - 1) / 2} + {3 * ( V - 1) V / 2} + V ] */


#include <stdio.h>
#include <stdlib.h>

int main()
{
        unsigned long long int T=0, K=0, V=0, i, j, total=0;

        FILE* fp = fopen("ip.txt", "r");
        if(NULL == fp)
                exit(1);

		// scan the number of testcases
        fscanf(fp, "%d\n", &T);


        for(int t = 1; t <= T; ++t){
        		//scan the number of color levels and the max permissible difference in color levels to be bland
                fscanf(fp, "%llu %llu", &K, &V);
                total = ((3 * V * V) + 3 * V + 1) * (K - V + 1) + (((V - 1) * V * ( 2 * V - 1)) / 2) + ((3 * ( V - 1) * V) / 2 ) + V;
                    //total = K + 1 + (V * (V + 1) * (3 * K - 2 * V + 2));
                
                printf("Case #%d: %llu\n", t, total);
        }
}

				
		
		
