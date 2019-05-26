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
    int buffer[512];
    char imageName[8];

    // fread(&buffer, 1, 512, inptr);

    // // somewhere need to increment filenumber++; to add another # to each file

    // // creates a filename that starts at 000.jpg and interates through each integer, each iteration
    // // sprintf(filename, "%03i.jpg", fileNumber)

    // //need a while loop because we read through the blocks of 512 until end of file... aka completion
    while( feof(inptr) == 0)
    {
        fread(&buffer, 1, 512, inptr);
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(imageName, "%03i.jpg", fileNumber);
            // printf("%i\n", fileNumber);

            FILE *outptr = fopen(imageName, "w");

            fwrite(buffer, 1, 512, outptr);

            // Go on to the next file
            fileNumber++;
        }
    }
    printf("%i\n", fileNumber);
    // // & is the bitwise AND operator... it compares 2 values bit by bit, if both values in a give position are 1, it will return a one in that position
    // // so the 4th value has three 1s to start with like 11100000 (when comparing buffer[3] and 0xf0) it will return true
    // if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    // {

    // }

    printf("Completed While Loop!\n");
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