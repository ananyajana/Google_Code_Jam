/*  Google Code Jam I/O women 2015, problem D: Googlander
*/

#include <stdio.h>
#include <stdlib.h>

int memo[26][26] = {-1};	// initializing the memoization array with a value of -1

int rec_solve(int r, int c){
	if((r == 1) || (c == 1))
		return 1; 
	if(memo[r][c] != -1)
		return memo[r][c];
		
	int ans = 0;
	for(int i = 1; i <= r; ++i)
		ans += rec_solve(c - 1, i);
	memo[r][c] = ans;
	return ans;
}

int main()
{
    int T = 0, R = 0, C = 0;

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);
    //printf("T = %d\n", T);

    for(int t = 1; t <= T; ++t){

        fscanf(fp, "%d %d", &R, &C);
        
        printf("case #%d: %d\n", t, rec_solve(R, C));
    }
}
