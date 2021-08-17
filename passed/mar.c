#include <stdio.h>

int main()
{
    int h,height, i, j;
    do
    {
        printf("please give me a height between 1-23: ");
        scanf("%d", &height);
    }    
    while (height < 1 || height > 8);

    printf("\n");    
    for (i = 0; i < height; i++) {

        for (j = 0; j < height - i - 1; j++)
            printf(" ");
        for (j = 0; j < i + 1; j++)
            printf("#");

        printf("\n");
    }

    
}




