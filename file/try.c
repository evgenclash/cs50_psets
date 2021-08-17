#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char *word = NULL   ;
    // char name[] = "texxt.txt";
    FILE *file = fopen("hello.txt", "w");
    if (file == NULL)
    {
        printf("Could not open the file");
        exit (1);
    }
    printf ("Introduce a sentence for the new file: \n");
    scanf ("%s",word);
    printf ("%s", word);
    // fprintf (file, word);
    fclose (file);
}