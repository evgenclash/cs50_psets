#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    int key, n, i, c;
    
    
    if ( argc != 2)
    {
        printf ("Usage: ./caesar key");
        
        return 1;
    }
    // covvert string in a int
    key = atoi(argv[1]);
    
    if (key==0)
    {
         printf ("Usage: ./caesar key");
         
         return 1;
    }
 
        // Get imput from the user
   
    string word = get_string("Give your phrase: ");
    

    printf ("ciphertext: ");
        // TODO: Return encrypted code
        for (i = 0, n = strlen(word); i < n; i++)
        {
            if (isupper(word[i]))
            {
                c = (((int)word[i] - 65 + key)%26) +65;
                printf ("%c",(char) c);
            }
            else if (islower(word[i]))
            {
               c = (((int)word[i] - 97 + key)%26) +97;
               printf ("%c",(char) c);
            }
            else 
            {
                printf("%c", word[i]);
            }
        
        }
    
    
    printf("\n");
        
    return 0;

}

