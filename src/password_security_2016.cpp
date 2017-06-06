/*  Google Code Jam I/O women 2016, problem D: Password security
For a single string as input(small input), we can swap the non-same characters
in any two locations to get


Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int T, N, i, j, k, l;
    char** ptr = NULL;
    char str[26] = {1};	// array to keep count whether the character has appeared already or not
    char temp;

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){
    	
    	fscanf(fp, "%d", &N);
    	ptr = (char**)calloc(1, sizeof(char*));
    	
		for(i = 0; i < N; ++i){
    		ptr[i] = (char*)calloc(27,  sizeof(char));
    		ptr[i][26] = '\0';
    		fscanf(fp, "%s\n", ptr[i]);
    	
			if(strlen(ptr[i]) == 1)	// if the input string is of length 1, then then there is no string possible where the condition will be fulfilled
    			printf("Case %d: IMPOSSIBLE\n", t);
    		else{	// if the string length is not 1, then we try to swap the first two characters of the string(only when N=1)
				for(j = 0; j < strlen(ptr[i]); ++j){
	    			str[ptr[i][j]-'A'] = 0;
				}
				temp = ptr[i][0];
				ptr[i][0] = ptr[i][1];
				ptr[i][1] = temp;
				l = strlen(ptr[i]);
				for(k = 0; k < 26; ++k){
					if(str[k] == 1){
						ptr[i][l] = str[k]+'A';
						++l;
					}
				}
				printf("Case %d: %s\n", t, ptr[i]);
			}
			
		}	
    }
}
