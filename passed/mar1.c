#include <stdio.h>
#include <cs50.h>

int main(void )
{
    float plata, platit, luni,rest;
    // get all necessary imputs
    plata = get_int("Cit costa abonamentul lunar? \n");
    luni = get_int ("cite luni ai platit? \n");
    
   do 
    {
        
        platit = get_int ("Cit ai platit in luna aceasta? \n");
        
        if (platit == 1)
        {
            printf("Ati stopat calculul: ");
            rest = rest + platit - plata;
            printf("Soldul ramas: %f\n", rest);
        }
    }
    while (platit == 1);
    
    
}