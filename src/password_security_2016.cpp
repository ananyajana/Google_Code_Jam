/*  Google Code Jam I/O women 2016, problem D: Password security
For a single string as input(small input), we can swap the non-same characters
in the first two places to get a modified password. After the password, we start
appending the remaining characters. If a character appears twice or  more in the
input string, then printing ABCD..XYZ is sufficient.


Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX	26



int main()
{
    int T, N, i, j, k, l;
    char** ptr = NULL;
    int str[MAX];	// array to keep count whether the character has appeared already or not
    char temp;
    int flag = 0;


    
	FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);


    for(int t = 1; t <= T; ++t){
    	
    	flag = 0;	// initialize the flag to determine whetherr such output string is impossible is set to false every time a test case begins
    		//initialize the initial value in the str array to 1, this array keeps a count of whether the corresponding letter for an index is not yet seen in the input array
		for(k = 0; k < MAX; ++k)
			str[k] = 1;
    	
    	fscanf(fp, "%d", &N);
    	ptr = (char**)calloc(N, sizeof(char*)); // allocate a pointer 2 a two dimensional dynamically allocated array
    	
		for(i = 0; i < N; ++i){
    		ptr[i] = (char*)calloc((MAX+1),  sizeof(char)); //synamically allocate the space for the pointers to arrays
    		ptr[i][MAX] = '\0';
    		fscanf(fp, "%s", ptr[i]);
    	
			if(strlen(ptr[i]) == 1)	// if the input string is of length 1, then then there is no string possible where the condition will be fulfilled
				flag = 1;
    		else{	// if the string length is not 1, then we try to swap the first two characters of the string(only when N=1)
				for(j = 0; j < strlen(ptr[i]); ++j){
	    			--str[ptr[i][j]-'A'];	// decrement the count of the character in the count array
				}
				
				// swap the first two characters
				temp = ptr[i][0];
				ptr[i][0] = ptr[i][1];
				ptr[i][1] = temp;
				
				//getting the input string length so that we can start appending the remaining chracters from the end of the input string
				l = strlen(ptr[i]);
				
				for(k = 0; k < MAX; ++k){
					if(str[k] < 0){		//if some character has appeared twice in the input string, it means the original string ABCDEFG... XYZ is sufficient, there is no need to append. So break out of traversal of count array
						flag = 2;
						break;
					}
					else if(str[k] == 1){	//if all the characters in the input string has appeared only once in the input string, append the remaining characters 
						ptr[i][l] = k +'A';		// append
						++l;		// increment the index
					}
				}
			}
			
			// if the flag is 1, then no such string is possible, if the flag is 2, then ABCDEFG...XYZ is enough. else print the array which we created by appending
			if(1 == flag)
				printf("Case #%d: IMPOSSIBLE\n", t);
			else if(2 == flag)
				printf("Case #%d: ABCDEFGHIJKLMNOPQRSTUVWXYZ\n", t);
			else
				printf("Case #%d: %s\n", t, ptr[i]);
			
			// free the arrays holding the strings
			for(i = 0; i < N; ++i)
				if(ptr[i])
					free(ptr[i]);
			
			// free the pointer holding the address of the array of character pointers
			if(ptr)
				free(ptr);			
		}	
    }
}
