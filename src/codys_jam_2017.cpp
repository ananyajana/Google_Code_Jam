/*  Google Code Jam I/O women 2017, problem A: Cody's Jam
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0, N = 0;

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);
    //printf("T = %d\n", T);

    for(int t = 1; t <= T; ++t){

        fscanf(fp, "%d", &N);
        
        printf("case #%d:\n", t);
    }
}
