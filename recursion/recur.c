#include <stdio.h>


void suma( int tab[], int a);
int summ = 0;
int cop [3];
int main (void)
{
int b;
    printf ("give the lenght of the array\n");
    scanf ("%d",&b );
    int tab[b];
    for (int i = 0; i < b; i++)
    {
        printf ("Give %d number to sum\n", i+1);
        scanf ("%d",&tab[i] );
    }
    suma(tab, b);
    for (int i = 0; i < b; i++)
    {
        printf ("suma este %d\n", cop[i]);
    }    
}

void suma (int tab[],int a )
{
    if (a > 0)
    {
        suma (tab, a - 1);
    }
    cop [a] = tab [a];
   
}