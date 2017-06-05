/*  Google Code Jam I/O women 2016, problem D: Password security
For a single string as input(small input), we can swap the non-same characters
in any two locations to get


Author:Ananya Jana
*/

#include <stdio.h>



int main()
{
    int T, N, i;
    char** ptr = NULL;
    char string[26] = 1;	// array to keep count whether the character has appeared already or not

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){
    	fscanf(fp, "%d", &N);
    	ptr = (char**)calloc(1, sizeof(char*));
    	for(i = 0; i < N; ++i){
    		ptr[i] = (char*)calloc(26,  sizeof(char));
    		fscanf(fp, "%s\n", ptr[i]);
    		for(int j = 0; j < strlen(ptr[i]; ++j]){
    			string[ptr[i][j]-'A'] = 0;
			}
		}	
		printf("Case #%d: %llu\n", t, num_words[L]);
    }
}
