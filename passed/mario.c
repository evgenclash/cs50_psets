#include <cs50.h>
#include <stdio.h>

    
int main(void)
{
    int x, j, i;
    do
    {
        x = get_int("Give a numbver from 1 to 8:\n");
    }
    while  (x > 8 || x < 1);

    for ( i = 0; i<x; i++)
    {
        for ( j = 0; j<x-i-1; j++)
        
            printf (" ");
            
            
        for ( j=0; j<i+1; j++)
        
        printf ("#");
        printf ("  ");
      
        for (j=x+2; j<x+2+i+1; j++)
        printf ("#");
        
        printf("\n");
    }
}
