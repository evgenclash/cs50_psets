#include <stdio.h>

int fig(int number);
int main (void)
{
    int number, result;
    printf ("Give a number ");
    scanf ("%d", &number);
    result = fig (number);
    printf("Number of digits is %d\n", result);
}

int count = 0;
int fig (int number)
{
    if (number > 0 )
    {
        int k = number % 10;
        fig ( number/10 );
        count = count + k;
    }

    return count;
}