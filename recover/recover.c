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

    // //need a while loop because we repeat until end of file... aka completion
    // while()
    // {

    // }

    fread(&buffer, 1, 512, infile);

    // if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    // {

    // }

}
