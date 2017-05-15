/*  Google Code Jam I/O women 2016, problem B: Dance Around the Clock
Observation 1: If there are D number of dancers, then the initial pattern would repeat
after D/2 changes.
Observation 2: For even numbered dancers, the partners would always be odd numbered and
vice versa.
Observation 3: For odd numbered dancers, the partners would be one of - (10, 2), (2, 4), (4, 6), (6, 8), (8, 10)
Similaryly for odd numbered "	,		"		"		"	"	"	" - (1, 3), (9, 1), (7, 9), (5, 7), (3, 5) 
(Assuming there are only 10 dancers)
Observation 4: Initially the partners of dancer n would be (n-1) and (n+1) and from then incrementing one at each
step until wrapping up once they cross the range <1 - D>
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int T, N, K, D, temp, partner_left, partner_right;
    T = N = D = K = temp = partner_left = partner_right = 0;

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){
		// input the number of dancers, the number of one of the dancers and the number of turns the dance will go on
        fscanf(fp, "%d %d %d", &D, &K, &N);
        
        // number of pairs that can be formed from the D dancers
        temp = D / 2;
        
        // since the pattern of the dancers repeat after every D/2 number of turns, so we take only the remainder 
		if( N > temp){
        	N = N % temp;
		}
		
		//calculate the initial partners of the dancer K, taking care if K = D or K = 1
		if(K == D){
			partner_left = K - 1;
			partner_right = 1;
		}
		else if(K == 1){
			partner_left = D;
			partner_right = K + 1;
		}
		else{
			partner_left = K - 1;
			partner_right = K + 1;
		}
			
		printf("Case #%d:", t);
    }
}
