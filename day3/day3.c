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

    printf("Part1 --> bit stuff: %d\n", Part31(string));
    // printf("Part2 --> increased: %d\n", Part12(read_file("./day1/input.txt")));
}

int getBitLength(char *string)
{
    char *context = NULL;
    return strlen(strtok_r(string, "\n", &context));
}

int Part31(char *string)
{

    char *tmpstr = malloc(sizeof(string));
    strcpy(tmpstr, string);

    char *tempString;
    strcpy(tempString, string);

    // Get the length of one line
    int len = getBitLength(tempString);
    free(tempString);

    // char *oxygen = malloc(sizeof(int) * len);
    // char *co2 = malloc(sizeof(int) * len);

    int oxygen[len];

    for (int i = 0; i < len; i++)
    {
        // Count of 0s
        int count0 = 0;
        // Count of 1s
        int count1 = 0;

        // printf("len: %d", len);

        printf("Outer Iteration\n");
        char *tempstr;
        char *context = NULL;
        strcpy(tempstr, string);
        char *ptr = strtok_r(tempstr, "\n", &context);

        while (ptr != NULL)
        {
            if (strlen(ptr) == len)
            {
                // printf("%c\n", ptr[i]);
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
        // printf("Count 0: %d, Count 1: %d\n", count0, count1);

        // if (count0 > count1)
        // {
        //     oxygen[i] = 0;
        //     co2[i] = 1;
        // }
        // else if (count1 > count0)
        // {
        //     oxygen[i] = 1;
        //     co2[i] = 0;
        // }
        // else
        // {
        //     oxygen[i] = 1;
        //     co2[i] = 0;
        // }
        // Use the nice stack
    }
    return 1;
}