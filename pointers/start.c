#include <stdio.h>
#include <stdlib.h>
int calc(char string[]);
int main()
{
    int i = 0;
    char string[25];
    printf ("give a string \n");
    fgets (string, sizeof(string), stdin);
    
    i = calc(string);
    printf ("%d\n", i);
}

int calc(char string[])
{
    static int a = 0; 
    if (*string)
    {
        calc(string + 1);
        a++;
        printf("%s", string);
    }
     return a;
}
