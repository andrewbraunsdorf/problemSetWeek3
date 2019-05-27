#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // only take one argument
    if (argc != 2)
    {
        fprintf(stderr, "Usage: \"./recover <image>\" should have exactly one prompt, filename, after recover!\n");
        return 1;
    }

    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    // if file does not exist close
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s!\n", infile);
        return 2;
    }
    int fileNumber = 0;
    unsigned char buffer[512];
    char imageName[8];
    FILE *outptr = NULL;
    // fread(&buffer, 1, 512, inptr);

    // // somewhere need to increment filenumber++; to add another # to each file

    // // creates a filename that starts at 000.jpg and interates through each integer, each iteration
    // // sprintf(filename, "%03i.jpg", fileNumber)

    // //need a while loop because we read through the blocks of 512 until end of file... aka completion
    while (fread(&buffer, 512, 1, inptr) == 1)

        // // added something to image 049.jpg
        // while (feof(inptr) == 0)
    {
        // FILE *outptr = fopen(imageName, "w");
        // fread(&buffer, 512, 1, inptr);

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if there is a file already open close it for new jpeg file
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            // fread(&buffer, 1, 512, inptr);
            sprintf(imageName, "%03i.jpg", fileNumber);
            outptr = fopen(imageName, "w");
            fwrite(&buffer, 512, 1, outptr);

            // printf("%i\n", fileNumber);

            // Go on to the next file
            fileNumber++;
        }
        else if (fileNumber > 0)
            // while(fread(&buffer, 1, 512 ,inptr) == 1)
        {
            fwrite(buffer, 1, 512, outptr);
        }

        // else
        // {
        //     fread(&buffer, 1, 512, outptr);
        //     fwrite(&buffer, 1, 512, outptr);
        // }


    }
    // close input file (card.raw)
    fclose(inptr);

    // close last image file (xxx.jpg)
    fclose(outptr);

    printf("%i\n", fileNumber);
    // // & is the bitwise AND operator... it compares 2 values bit by bit, if both values in a give position are 1, it will return a one in that position
    // // if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
    // // so the 4th value has three 1s to start with like 11100000 (when comparing buffer[3] and 0xf0) it will return true
    // if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    // {

    // }

    printf("Completed While Loop!\n");
    return 0;
}

// // somewhere need to increment filenumber++; to add another # to each file

// // creates a filename that starts at 000.jpg and interates through each integer, each iteration
// // sprintf(filename, "%03i.jpg", number)

// //need a while loop because we repeat until end of file... aka completion
// while()
// {

// }

// // & is the bitwise AND operator... it compares 2 values bit by bit, if both values in a give position are 1, it will return a one in that position
// // so the 4th value has three 1s to start with like 11100000 (when comparing buffer[3] and 0xf0) it will return true
// if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
// {

// }