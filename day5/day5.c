#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "day5.h"
#include "../file/file.h"
#include "../list/list.h"

void Run5()
{
    char *string;
    string = (char *)malloc(20001);
    strcpy(string, read_file("./day5/input.txt"));
    printf("Part1 --> Line Intersections: %d\n", Part51(string));
}

int Part51(char *string)
{
    char *context = NULL;
    char tempString[strlen(string)];
    strcpy(tempString, string);
    int len = strlen(strtok_r(tempString, "\n", &context));
    strcpy(tempString, string);
    char *ptr = strtok_r(tempString, "\n", &context);
    int outerIndex = 0;
    int coordinates[4];
    int coordPairNum = 0;
    node *list = NULL;
    int intersections = 0;
    bool execLoop = true;
    bool nextLoop = true;
    while (ptr != NULL)
    {
        int charIndex = 0;
        if (strlen(ptr) == len)
        {
            char *contextLine = NULL;
            char *coordinate = strtok_r(ptr, " -> ", &contextLine);
            while (coordinate != NULL)
            {
                char *contextChar = NULL;
                char *coordChar = strtok_r(coordinate, ",", &contextChar);
                while (coordChar != NULL)
                {
                    coordinates[charIndex] = atoi(coordChar);
                    coordChar = strtok_r(NULL, ",", &contextChar);
                    charIndex++;
                    if (charIndex == 4)
                    {
                        charIndex = 0;
                    }
                }
                if (coordPairNum == 1)
                {
                    printf("\nCoordinate pair complete:\n    | (%d,%d) -> (%d,%d)\n", coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
                    if (coordinates[0] == coordinates[2])
                    {
                        if (coordinates[1] > coordinates[3])
                        {
                            for (int c = coordinates[3]; c <= coordinates[1]; c++)
                            {
                                if (!listContains(list, coordinates[0], c))
                                {
                                    push(&list, coordinates[0], c);
                                }
                                else
                                {
                                    intersections++;
                                }
                            }
                            printf("    | All coordinates of route calculated.\n");
                        }
                        else
                        {
                            for (int c = coordinates[1]; c <= coordinates[3]; c++)
                            {
                                if (!listContains(list, coordinates[0], c))
                                {
                                    push(&list, coordinates[0], c);
                                }
                                else
                                {
                                    intersections++;
                                }
                            }
                            printf("    | All coordinates of route calculated.\n");
                        }
                    }
                    else if (coordinates[1] == coordinates[3])
                    {
                        if (coordinates[0] > coordinates[2])
                        {
                            for (int c = coordinates[2]; c <= coordinates[0]; c++)
                            {
                                if (!listContains(list, c, coordinates[1]))
                                {
                                    push(&list, c, coordinates[1]);
                                }
                                else
                                {
                                    intersections++;
                                }
                            }
                            printf("    | All coordinates of route calculated.\n");
                        }
                        else
                        {
                            for (int c = coordinates[0]; c <= coordinates[2]; c++)
                            {

                                if (!listContains(list, c, coordinates[1]))
                                {
                                    push(&list, c, coordinates[1]);
                                }
                                else
                                {
                                    intersections++;
                                }
                            }
                            printf("    | All coordinates of route calculated.\n");
                        }
                    }
                    else
                    {
                        printf("    | Ignoring diagonal route.\n");
                    }
                    coordPairNum = 0;
                }
                else
                {
                    coordPairNum++;
                }
                coordinate = strtok_r(NULL, "  -> ", &contextLine);
            }
        }
        outerIndex++;
        ptr = strtok_r(NULL, "\n", &context);
    }
    printf("\nAll calculated coordinates:\n    | ");
    printList(list);
    return intersections;
}