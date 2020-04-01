
#include <stdio.h>
#include <string.h>
#include "math.h"
  
// d is the number of characters in the input alphabet 
#define d 256

void rabinkarp(char pattern[], char text[]) 
{ 
    int m = strlen(pattern); 
    int n = strlen(text); 
    int p = 0, t = 0; // hash value 
    int q = 11;
    
    int units = pow(10, m-1);
    for (int c=0; c<m; c++)
    {
        p = p + pattern[c]*units;
        t = t + text[c]*units;
        units = units/10;
    }
    
    int x;
    for (int c=0; c<(n-m); c++)
    {
        if (p%q==t%q)
        {
            if (p == t)
                printf("Match found at index: %d", c);
        }
        x = t-((pow(10, m-1))*text[c]);
        t = 10*x;
        t = t + text[c+m];
    }

} 
  
int main() 
{ 
    char text[] = "3141592653589793"; 
    char pattern[] = "26"; 
    rabinkarp(pattern, text); 
    return 0; 
} 
