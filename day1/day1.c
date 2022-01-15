#include "stdio.h"
#include <stdlib.h>
#include "string.h"
#include "day1.h"
#include "../file/file.h"

void Run1()
{
    char *string = read_file("./day1/input.txt");
    Part1(string);
}

void Part1(char string[]) {
    // char *string = read_file("./day1/input.txt");
    int i = 0;
    int stringLen = strlen(string);
    char currentChunk[4];
    char currentChunkBuf[4];
    int j = 0;

    int depth;
    int prevDepth;
    int increases = 0;
    int currentChunkCount = 0;

    while (i < stringLen)
    {
        if (string[i] == '\n' || string[i] == '\0')
        {
            i++;
            j = 0;
            currentChunkCount++;

            strcpy(currentChunk, currentChunkBuf);
            char currentChunkBuf[4] = "    ";

            depth = atoi(currentChunk);
            if (currentChunkCount != 0 && depth > prevDepth)
            {
                increases++;
            }
            prevDepth = depth;
        }
        else
        {
            currentChunkBuf[j] = string[i];
            i++;
            j++;
        }

        if (i == stringLen)
        {
            if ( depth > atoi(currentChunk))
            {
                increases++;
            }
        }
    }

    printf("Day 1:1 | Total Depth Increases: %d\n", increases);
}
