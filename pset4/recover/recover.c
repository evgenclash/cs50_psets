#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: Usage: ./recover image\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    char filename[8];
    FILE *img = NULL;
    unsigned char buffer[512];
    int numofimg = 0;
    int found = 0;
    while (fread (buffer,512 , 1, card )==1)
    {
        if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff &&  (buffer[3] & 0xf0)==0xe0)
        {
            if (found == 0)
            {
                sprintf(filename, "%03i.jpg", numofimg);
                img = fopen (filename, "w");
                if (img == NULL)
                {
                    return 3;
                }
                fwrite(&buffer, 512, 1, img);
                found = 1;
                numofimg++;
            }
            else if (found == 1)
            {
                fclose (img);
                sprintf(filename, "%03i.jpg", numofimg);
                img = fopen (filename, "w");
                if (img == NULL)
                {
                    return 3;
                }
                fwrite(&buffer, 512, 1, img);
                numofimg++;
            }
        }
        else 
        {
            if (found == 1)
            {
                fwrite(&buffer, 512, 1, img);
            }
        }   
    }
        fclose(img);
        fclose(card);
}