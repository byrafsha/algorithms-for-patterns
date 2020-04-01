
#include <stdio.h>
#include <string.h>
#include "math.h"
#include <bits/stdc++.h> 
using namespace std; 

#define characters 256

void badCharacters(string pattern, int m, int badC[characters]) 
{ 
	for (int c = 0; c < characters; c++) 
		badC[c] = -1;
	for (int c = 0; c < m; c++) 
		badC[(int) pattern[c]] = c; 
} 

void moore( string text, string pattern) 
{ 
	int m = pattern.size(); 
	int n = text.size(); 

	int badC[characters]; 
	badCharacters(pattern, m, badC); 

    int c=0;
    while (1)
    {
		if (c>(n-m))
			break;
        int d = m-1;
        while (d>=0 && pattern[d]==text[c+d])
                d--;
        if (d<0)
        {
            cout<<"Pattern matches at shift: "<<c<<endl;
            c = c + (c + m < n)? m-badC[text[c + m]] : 1;
        }
        else
        {    c = c + max(1, d - badC[text[c + d]]);
        }
    }
} 

int main() 
{ 
	string txt= "ABAAABCD"; 
	string pat = "ABC"; 
	moore(txt, pat); 
	return 0; 
} 