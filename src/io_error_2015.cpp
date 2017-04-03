#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T=0, N=0;
	char* S_arr = '\0';
	char input = 0, current = 0;

	FILE* fp = fopen("ip.txt", "r");
	
	fscanf(fp, "%d", &T);
	//printf("T = %d\n", T);	
	
	for(int t = 1; t <= T; ++t){
		fscanf(fp, "%d", &N);
		S_arr = (char*)calloc(N + 1, sizeof(char));
		for(int i = 0; i < N ; ++i){
			current = 0;
			for(int j = 0; j < 8; ++j){
				fscanf(fp, "%c", &input);
				if(c)
			}
		}
		printf("Case #%d: %d\n", t, max);
	}
}
				
		
		
