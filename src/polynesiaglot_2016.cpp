/*  Google Code Jam I/O women 2016, problem C: Polynesiaglot
First find out the total number of words: (V+C) to the power L(since in any of the position we can have any of V+C letters)
To calculate the total number of invalid words, we make  an observation that for any word to be invald, there is at least
one CC inside it or it ends with C. 
The number of words having at least one CC is C square * (V + C) to the power L-2(since other positions can be filled with 
any other letter) * (L - 1), since this CC can appear in any one of the places from 1 to L - 1.
The number of words ending with C is C*(V+C) to the power (L - 1)

In this approach we need to determine the intersection between the two sets: The number of words ending in a consonant and the number of
words having at least two consecutive consonants.

Other appraach(from google code jam contest analysis):
W(X) = Wc(X) + Wv(X)
W(X) - total number of valid words of length X
Wc(X) - total number of words of length X and beginning with a consonant
Wv(X) - "						"								vowel

Wc(X) = C * Wv(X - 1)
Wv(X) = V * W(X - 1)

Hence
W(X) = V * W(X - 1) + V * C * W(X - 2)
 

Since this is a recusrsive formula, memoization is used.
We will take the modulo value at each step.
Author:Ananya Jana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE	501
const int mod_val = 1000000007;


int main()
{
    unsigned int T, C, V, L, i;
    T = C = V = L = 0;
    unsigned long long int num_words[MAX_VALUE] = {0};		// array for Memoization, initialized to all 0s.

    FILE* fp = fopen("ip.txt", "r");

    fscanf(fp, "%d", &T);

    for(int t = 1; t <= T; ++t){
    	// clear the memoization array at the beginning of each execution
    	memset(num_words, 0, MAX_VALUE);
    	
        fscanf(fp, "%u %u %u", &C, &V, &L);
        
        // set the base case values i.e. L = 0 and L = 1
		num_words[0] = 1;
        num_words[1] = V;
        
        // calculating the number of valid words of given length when L >= 2
        for(i = 2; i <= L; ++i){
			// the recusrive formula for calculating the number of words
        	//num_words[i] = (V * (num_words[i - 1] + C * num_words[i - 2])) %  mod_val;
        	num_words[i] = (V * ((num_words[i - 1] + C * num_words[i - 2])%  mod_val)) %  mod_val;
		}
        		
		printf("Case #%d: %llu\n", t, num_words[L]);
    }
}
