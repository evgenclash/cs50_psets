#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int ssize, esize,y=0;
    // TODO: Prompt for start size
    
    do
    {
        ssize = get_int ("Start size: \n");
    } 
    while (ssize<9);

    // TODO: Prompt for end size

    do
    {
        esize = get_int ("End size: \n");
    }
    while (esize<ssize);
    
    // TODO: Calculate number of years until we reach threshold
   
   while (ssize<esize)
   {
         ssize+=ssize/3-ssize/4;
         y+=1;
         
    
   }
    
    
    
    

    // TODO: Print number of years
    printf ("Years: %i \n", y);
   
}