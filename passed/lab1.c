#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)

{
    int i, y, sum1, sum2, n, m;
    
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");
    
    for ( i = 0, n = strlen (player1); i < n; i++)
        {
             sum1 = (int) player1 [i] + sum1;
            
        }
        
    for ( y = 0, m = strlen(player2); i < m; i++)
        {
             sum2 = (int) player2[i] + sum2;
            
        }
        if (sum1 < sum2)
        {
            printf ("Player 2 wins \n");
        }
        else if (sum1>sum2)
        {
            printf ("Player2 wins \n");
        }
        
        else 
        {
            printf ("Tie!");
        }
        
        
        printf ("\n");
}