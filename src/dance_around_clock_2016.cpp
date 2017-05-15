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
    int T, N, K, D;
    T = N = D = K = 0;

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){

        fscanf(fp, "%d %d %d", &D, &K, &N);
        
		
		printf("Case #%d:", t);
    }
}
