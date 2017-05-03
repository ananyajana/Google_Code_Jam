/* Author:Ananya Jana */
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int T = 0, N = 0, D = 0;
        int yet_to_fill = 0, t1 = 0, t2 = 0;

        FILE* fp = fopen("ip.txt", "r");

        fscanf(fp, "%d", &T);
        //printf("T = %d\n", T);

        for(int t = 1; t <= T; ++t){
                N = D = 0;
		yet_to_fill = 15;
                fscanf(fp, "%d %d", &D, &N);
                printf("case #%d:\n", t);

                if(N <= 14){
			if(N == 0)
				printf("I\n");
			else{
				t1 = N % 7;
				t2 = N / 7;
				if(t2 > 0){
					for(; t2 > 0; --t2)
						printf("I/O/I/O/I/O/I/O\n");
				}
				switch(t1){
					case 1:
						printf("I/O////////////\n");
						break;
					case 2:
						printf("I/O/I//////////\n");
						break;
					case 3:
						printf("I/O/I/O////////\n");
						break;
					case 4:
						printf("I/O/I/O/I//////\n");
						break;
					case 5:
						printf("I/O/I/O/I/O////\n");
						break;
					case 6:
						printf("I/O/I/O/I/O/I//\n");
						break;
				}
			}			
                }
                else{
                        printf("I/O/I/O/I/O/I/O\nI/O/I/O/I/O/I/O\n");
                        N -= 14;
                        t1 = N % 21;
                        t2 = N / 21;
                        for(; t2 > 0; --t2)
                                printf("I/O/I/O/I/O/I/O\n");
						switch(t1){
								case 1:
										printf("I//////////////\n");
										break;	
								case 2:
										printf("//O////////////\n");
										break;
								case 3:
										printf("IOO////////////\n");
										break;
								case 4:
										printf("I/O////////////\n");
										break;
								case 5:
										printf("IOOOI//////////\n");
										break;
								case 6:
										printf("I/OOI//////////\n");
										break;
								case 7:
										printf("I/O/I//////////\n");
										break;
								case 8:
										printf("I/OOIOO////////\n");
										break;
								case 9:
										printf("I/O/IOO////////\n");
										break;
								case 10:
										printf("I/O/I/O////////\n");
										break;
								case 11:
										printf("I/O/IOOOI//////\n");
										break;
								case 12:
										printf("I/O/I/OOI//////\n");
										break;
								case 13:
										printf("I/O/I/O/I//////\n");
										break;
								case 14:
										printf("I/O/I/OOIOO////\n");
										break;
								case 15:
										printf("I/O/I/O/IOO////\n");
										break;
								case 16:
										printf("I/O/I/O/I/O////\n");
										break;
								case 17:
										printf("I/O/I/O/IOOOI//\n");
										break;
								case 18:
										printf("I/O/I/O/I/OOI//\n");
										break;
								case 19:
										printf("I/O/I/O/I/O/I//\n");
										break;
								case 20:
										printf("I/O/I/O/I/O/IOO\n");
										break;
						}
										
                }
        }
}
