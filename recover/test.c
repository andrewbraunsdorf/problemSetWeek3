#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buffer[50];

int course = 50;

sprintf(buffer,"CS%d rocks!", course);

printf("%s\n", buffer);
}