/*  Google Code Jam I/O women 2014, problem A: Saturnalia

Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAXLEN	70


int main()
{
	int N, T, len, i;
	N = T = 0;
	char arr[MAXLEN + 1], ch;
	ch = 'a';
	
	FILE* fp = fopen("ip.txt", "r");
	
	// if the file is not valid, exit
	if(NULL == fp){
		printf("Error, Can't open file");
		exit(1);
	}
	
	fscanf(fp, "%d\n", &T);
	
	for(int t = 1; t <= T; ++t){
    		//fscanf(fp, "%c", &ch); // scanning the strings one by one
    		
    		for(i = 0; i < MAXLEN; ++i){
    			arr[i] = '\0';
    		}
    		
    		for(i = 0; i < MAXLEN; ++i){
    			fscanf(fp, "%c", &ch);
    			if(ch != '\n')
    				arr[i] = ch;
    			else 
    				break;
    		}
    		arr[i] = '\0';
    		//fscanf(fp, "%c", &ch);
    		
    		len = i;
    		if(len == 0){
    			--t;
    			continue;
    		}
    		//printf("len = %d:\n", len);
    		
    		
    		printf("Case #%d:\n", t);
    		printf("+");
    		for(i = 1; i <= len + 2; ++i)
    			printf("-");
    		printf("+\n| %s |\n+", arr);
    		for(i = 1; i <= len + 2; ++i)
    			printf("-");
    		printf("+\n");
	}
	
	fclose(fp);
}
