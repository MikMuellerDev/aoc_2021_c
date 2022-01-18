#include "stdio.h"
#include <stdlib.h>
#include "string.h"
#include "day3.h"
#include "../file/file.h"

void Run3()
{
    char *string;
    string = (char *)malloc(20001);
    strcpy(string, read_file("./day3/input.txt"));

    printf("Part1 --> increased: %d\n", Part31(string));
    // printf("Part2 --> increased: %d\n", Part12(read_file("./day1/input.txt")));
}

int getBitLength(char *string)
{
    char *context = NULL;
    return strlen(strtok_r(string, "\n", &context));
}

int Part31(char *string)
{

    char *tempString;
    strcpy(tempString, string);
    int len = getBitLength(tempString);

    int init_size = strlen(string);
    char *context = NULL;

    char *ptr = strtok_r(string, "\n", &context);
    char *rawInstruction;
    rawInstruction = (char *)malloc(10);
    int instructionIndex = 0;

    while (ptr != NULL)
    {
        for (int i = 0; i < len; i++)
        {
            // DO THE ACTUAL SPLITTING
        }

        if (strlen(ptr) == len)
            printf("%s\n", ptr);
        ptr = strtok_r(NULL, "\n", &context);
        // Use the nice stack
    }
    return 1;
}