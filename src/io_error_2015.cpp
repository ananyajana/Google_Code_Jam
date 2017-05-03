/* Author:Ananya Jana */
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int T=0, N=0, i, j;
        unsigned char* S_arr = '\0';
        unsigned char input, current;

        FILE* fp = fopen("ip.txt", "r");
        if(NULL == fp)
                exit(1);

		// scan the number of testcases
        fscanf(fp, "%d\n", &T);


        for(int t = 1; t <= T; ++t){
        		//scan the number of character bytes present in the current test case
                fscanf(fp, "%d\n", &N);
                
                //allocate space to keep N number of characters
                S_arr = (unsigned char*)calloc(N + 1, sizeof(unsigned char));
                
                // for each character, scan the 8 characters i.e. a combination of Is and Os that has to be converted to 1s and 0s
                for(i = 0; i < N ; ++i){
                        current = 0;
                        for(j = 0; j < 8; ++j){
                                fscanf(fp, "%c", &input);

                                //if the character is I, then the corresponding bit is 1, else if the chracter is O, the corresponding bit is 0
                                // converting the 8 chracter string composed of Is and Os into 8 bit byte
                                if(input == 'I')
                                        current |= 0x01;
                                
								// the last bit of the chracter doesn't require shifting        
                                if(j != 7)
                                	current = current << 1;       
                        }
                        S_arr[i] = current;
                }
                S_arr[i] = '\0';
                printf("Case #%d: %s\n", t, S_arr);
        }
}

				
		
		
