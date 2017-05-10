/*  Google Code Jam I/O women 2016, problem B: Dance Around the Clock
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
