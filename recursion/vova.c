#include<stdio.h>
#include <cs50.h>
#include <string.h>

int lenght, minimum;
int max(int elements[],int b);
int main (void)
{
    // const int 5 = 5;
    int minim ;
    int elements[] = {0, 2, 4, 6, 8, 9};

    lenght = sizeof(elements)/sizeof(int);

    minim = max(elements, lenght);
    printf ("%d\n", minim);
}

int max(int elements[],int b)
{
    // int minimum = 0;
    // for (int i = 0; i < lenght; i++)
    // {
    //     if (minimum < elements[i])
    //     {
    //         minimum = elements[i];
    //     }
    // }

    if (b > 0)
    {
        max(elements,b -1);
        if (minimum < elements[b])
        {
            minimum = elements[b];
            printf ("%d", elements[b]);
        }
    }
    else
    {
        minimum = elements[b];
        printf ("%d",elements[b] );
    }
    return minimum;
}