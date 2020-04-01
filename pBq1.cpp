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