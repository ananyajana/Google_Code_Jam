/*  Google Code Jam 2017, problem B: Tidy Numbers
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int T = 0, num;	//K is the size of the pancake flipper. 2 <= K <= S
    char *str = NULL;
    bool flag = false;		// flag to tell whether there is any sad face in the string
	
	FILE* fp = fopen("ip.txt", "r");
	
	// if the file is not valid, exit
	if(NULL == fp){
		printf("Error, Can't open file");
		exit(1);
	}
	
    fscanf(fp, "%d", &T);
	
    for(int t = 1; t <= T; ++t){
    	fscanf(fp, "%d", &num);
	}
}
