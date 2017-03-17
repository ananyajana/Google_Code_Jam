#include <stdio.h>
#include <stdlib.h>

int main()
{
        int T = 0, N = 0, D = 0;
        int yet_to_print = 0, t1 = 0, t2 = 0;

        FILE* fp = fopen("ip.txt", "r");

        fscanf(fp, "%d", &T);
        //printf("T = %d\n", T);

        for(int t = 1; t <= T; ++t){
                N = D = yet_to_print = 0;
                fscanf(fp, "%d %d", &D, %N);
                printf("case #%d:\n", t);

                if(N <= 14){
                        t1 = N % 7;
                        t2 = N / 7;
                        if(t2 > 0){
                                for(; t2 > 0; --t2)
                                        printf("I/O/I/O/I/O/I/O\n");
                        }
                        if(t1 = 1)
                                printf("I");
                        for(; t1 >= 2; t1 -= 2)
                                printf("/O/I");
                        if(N == 1)
                                printf("/O");
                        printf("\n");
                }
                else{
                        printf("I/O/I/O/I/O/I/O\nI/O/I/O/I/O/I/O\n");
                        N -= 14;
                        t1 = N % 21;
                        t2 = N / 21;
                        for(; t2 > 0; --t2)
                                printf("I/O/I/O/I/O/I/O\n");
                }
        }
}
