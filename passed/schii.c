#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int compute_string(string word);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // promt words
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");
    
    // recieve score
    int score1 = compute_string(word1);
    int score2 = compute_string(word2);
    
    // give the result
    if (score1 > score2)
    {
        printf ("Player 1 wins \n");
    }
    else if (score1<score2)
    {
        printf ("Player2 wins \n");
    }
        
    else 
    {
        printf ("Tie!");
    }

}
    // Calculation of the score
    
int compute_string(string word)
{
    int i, n, m, sum = 0;
    char c;
    
    for (i = 0, n = strlen(word); i < n; i++)
    {
        c = toupper(word[i]);
        m = c - 65;
        sum = sum + POINTS[m];
    }
    
    return sum;
}