/*  Google Code Jam I/O women 2016, problem C: Polynesiaglot
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int T, C, V, L, num_words;
    T = C = V = L = num_words = 0;

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){
        fscanf(fp, "%d %d %d", &C, &V, &L);
        
        
			
		printf("Case #%d: %d\n", t, num_words);
    }
}
