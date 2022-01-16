#include "stdio.h"
#include <stdlib.h>
#include "string.h"
#include "day1.h"
#include "../file/file.h"

void Run1()
{
    char *string;
    string = (char *)malloc(20001);
    strcpy(string, read_file("./day1/input.txt"));

    printf("Part1 --> increased: %d\n", Part1(string));
    printf("Part2 --> increased: %d\n", Part2(read_file("./day1/input.txt")));
}

int Part1(char *string)
{
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
            if (depth > atoi(currentChunk))
            {
                increases++;
            }
        }
    }

    return increases + 1;
}

int Part2(char *inputString)
{
    // "Prepare" the string into a array of ints

    // WTF oneliner was causing fuck
    int chunkIndex = 0;
    int depthsIndex = 0;
    int arrayLength = 0;
    int stringIndex = 0;

    int depthsLength = 1;
    int stringLength = strlen(inputString);
    char currentChunk[4];

    // Calculate number of measurements that will be put into depths
    while (stringIndex < stringLength)
    {
        if (inputString[stringIndex] == '\n')
        {
            depthsLength++;
        }
        stringIndex++;
    }

    stringIndex = 0;

    int depths[depthsLength];

    while (stringIndex < stringLength)
    {
        if (inputString[stringIndex] == '\n' || inputString[stringIndex] == '\0')
        {
            chunkIndex = 0;
            depths[depthsIndex] = atoi(currentChunk);
            arrayLength++;
            depthsIndex++;
        }
        else
        {
            currentChunk[chunkIndex] = inputString[stringIndex];
            chunkIndex++;
        }

        stringIndex++;

        if (stringIndex >= stringLength)
        {
            depths[depthsIndex] = atoi(currentChunk);
        }
    }
    free(inputString);
    int newDepths[depthsLength - 2];

    int newDepthsIndex = 0;
    int measurement = 0;
    int prevMeasurement = 0;
    int increases = 0;
    while (newDepthsIndex < depthsLength)
    {
        if (newDepthsIndex + 1 < depthsLength && newDepthsIndex + 2 < depthsLength)
        {
            measurement = depths[newDepthsIndex] + depths[newDepthsIndex + 1] + depths[newDepthsIndex + 2];
            if (newDepthsIndex != 0 && measurement > prevMeasurement)
            {
                increases++;
            }
            prevMeasurement = depths[newDepthsIndex] + depths[newDepthsIndex + 1] + depths[newDepthsIndex + 2];
        }
        newDepthsIndex++;
    }

    return increases;
}