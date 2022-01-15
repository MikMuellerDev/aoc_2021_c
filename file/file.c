#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(char file_name[])
{
    char *buffer = 0;
    long length;
    FILE *f = fopen(file_name, "rb");

    if (f)
    {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer)
        {
            fread(buffer, 1, length, f);
        }
        fclose(f);
    }

    if (buffer)
    {
        return buffer;
    }
    else
    {
        return "";
    }
}