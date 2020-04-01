
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

void generateLPS(int m, char* pattern, int*LPS) 
{ 
    int suffix = 0; 
  
    for (int c=1; c<m; c++) //start at 1 because LPS[0]=0
    {
        if (pattern[c]==pattern[m]) 
        {
            suffix++;
            LPS[c]=suffix;
        }
        else
        {
            if (suffix==0)
            {
                LPS[c]=0;
            }
            else
            {
                suffix = LPS[suffix-1];
                c--;  //stay on the index
            }
        }
    }
} 


void KMP(char* text, char* pattern) 
{ 
    int m = strlen(pattern); 
    int n = strlen(text); 
  
    int LPS[m] = {0};
    generateLPS(m, pattern, LPS); 
  
    int t=0;
    int p=0;
    
    while (t<n)
    {
        if (pattern[p]==text[t])
        {
            p++;
            t++;
        }
        
        if (p==m)
        {
            cout<<"Pattern found at index: "<<t-p<<endl;
            p=LPS[p-1];
        }
        else if (pattern[p]!=text[t] && t<n)
        {
            //mismatch after p matches
            if (p!=0)
                p=LPS[p-1];
            else
                t++;
        }
    }
}


int main()
{
    char Text[] = "baabaababaabaaba";
    char Pattern[] = "abaa";
    KMP(Text, Pattern);

    return 0;
}
