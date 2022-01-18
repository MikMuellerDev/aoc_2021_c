#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "day3.h"
#include "../file/file.h"

void Run3()
{
    char *string;
    string = (char *)malloc(20001);
    strcpy(string, read_file("./day3/input.txt"));

    printf("Part1 --> Power Consumption: %d\n", Part31(string));
    // printf("Part2 --> increased: %d\n", Part12(read_file("./day1/input.txt")));
}

int Part31(char *string)
{
    char *context = NULL;

    char tempString[strlen(string)];
    strcpy(tempString, string);
    int len = strlen(strtok_r(tempString, "\n", &context));
    strcpy(tempString, string);

    int *gamma = malloc((sizeof(int) * len) + 1);
    int *epsilon = malloc((sizeof(int) * len) + 1);

    for (int i = 0; i < len; i++)
    {
        strcpy(tempString, string);
        char *context = NULL;

        char count0 = 0;
        char count1 = 0;
        char *ptr = strtok_r(tempString, "\n", &context);

        while (ptr != NULL)
        {
            if (strlen(ptr) == len)
            {
                // printf("%c", ptr[i]);
                switch (ptr[i])
                {
                case '1':
                    count1++;
                    break;
                case '0':
                    count0++;
                    break;
                default:
                    printf("ERROR, unknown bit: %c", ptr[i]);
                    break;
                }
            }
            ptr = strtok_r(NULL, "\n", &context);
        }
        // printf("\nCount 0: %d, Count 1: %d\n", count0, count1);

        if (count0 > count1)
        {
            epsilon[i] = '1';
            gamma[i] = '0';
        }
        else if (count1 > count0)
        {
            epsilon[i] = '0';
            gamma[i] = '1';
        }
    }

    char gammaTemp[len + 1];
    char epsilonTemp[len + 1];

    for (int j = 0; j < len; j++)
    {
        gammaTemp[j] = (char) gamma[j];
    }
    gammaTemp[len + 1] = '\0';

    for (int j = 0; j < len; j++)
    {
        epsilonTemp[j] = (char) epsilon[j];
    }
    return strtol(gammaTemp, NULL, 2) * strtol(epsilonTemp, NULL, 2);
    return 0;
}