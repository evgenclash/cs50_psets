#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{

    //Ensure only one command line argument//
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    //Open File//
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File not working\n");
        return 1;
    }

    //Create buffer of size 512 bytes to store data from file that is being read//
    unsigned char buffer[512];
    //Set Bool value of already found first jpeg to false//
    bool already_found_jpeg = false; 
    //Create filename length of 8 that will be of new jpegs
    char filename[8];
    FILE *img = NULL;
    //num_of_imgs counter//
    int num_of_imgs = 0;
    while(fread(buffer, 512, 1, file) == 1)
    {
        //If start of new jpeg//
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If first jpeg, start writing the very first file// 
            if (already_found_jpeg == false) 
            {
                sprintf(filename, "%03i.jpg", num_of_imgs);
                img = fopen(filename, "w");
                if (img == NULL)
                {
                    return 3;
                }
                //Write from buffer into new file//
                fwrite(&buffer, 512, 1, img);
                num_of_imgs ++;
                already_found_jpeg = true;
            }
            //Else if already found a jpeg meaning it's not the first jpeg then close file, so you can open up a new file that can be written too
            else if (already_found_jpeg == true)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", num_of_imgs);
                img = fopen(filename, "w");
                if (img == NULL)
                {
                    return 3;
                }
                //Write from buffer into new file//
                fwrite(&buffer, 512, 1, img);
                num_of_imgs ++;
            }
        }
        //else if not found the jpeg headers and already found first jpeg keep writing to file
        else 
        {
            if (already_found_jpeg == true)
            {
                fwrite(&buffer, 512, 1, img);
            }
        }
        //Close all files//
    }
    fclose(img);
        fclose(file);
}