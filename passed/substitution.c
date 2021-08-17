#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int i,n, in, im, count=0;
    string word;
    
     if (argc != 2)
    {
        printf("Usage: ./substitution key");
        
        return 1;
    }
    
    
    else if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key");
         
        return 1;
    }
    
    else
    {
       for (i = 0; i < 26; i++ ) 
       {
           if (isalpha(argv[1][i]))
           {
                   for (im = 0; im < 26; im++)
                   {
                      
                       if ((int)toupper(argv[1][im])-65==i) 
                       {
                           count++;
                           printf("%i\n",count);
                       }
                    }
            }
            /*else
            {
                printf ("Error");
            */

       }   
        
    }
    if (count!=26)
        {
           printf("Key must contain 26 different characters.");
           
           return 1;
        }
        
    word = get_string("plaintext: ");
printf("ciphertext: ");
    

    int b, k, y, sum = 0;
    char c;

    for (b = 0, k = strlen(word); b < k; b++)
    {
         if (isupper(word[b]))
        {
            y = (int)word[b] - 65;
            printf ("%c", toupper(argv[1][y]));
            
        }
         else if (islower(word[b]))
        {
            y = (int)word[b] - 97;
            printf ("%c", tolower(argv[1][y])); 
        }
         else
        {
            printf("%c", word[b]);
        }
        
    }

    return 0;
}
