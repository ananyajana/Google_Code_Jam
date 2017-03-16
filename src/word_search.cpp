#include <stdio.h>
#include <stdlib.h>

int main()
{
        int T = 0, N = 0, D = 0;
        int yet_to_print = 0;

        FILE* fp = fopen("ip.txt", "r");

        fscanf(fp, "%d", &T);
        //printf("T = %d\n", T);

        for(int t = 1; t <= T; ++t){
                N = D = yet_to_print = 0;
                fscanf(fp, "%d %d", &D, %N);
                printf("case #%d:\n", t);

                if(N > 14){
                        yet_to_print = N - 14;
                        for(int i = 0; i < 2; ++i){
                                for(int k = 0; k < 5; ++k)
                                        printf("iI/O");
                                printf("\n");
                        }
        }
}
