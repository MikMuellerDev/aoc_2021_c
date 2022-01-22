#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "day5.h"
#include "../file/file.h"
#include "./list/list.h"

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
    node *markedList = NULL;
    int intersections = 0;
    bool execLoop = true;
    bool nextLoop = true;

    push(&list, -111, -111);
    while (ptr != NULL)
    {
        int charIndex = 0;
     
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
                    int x1 = coordinates[0];
                    int y1 = coordinates[1];
                    int x2 = coordinates[2];
                    int y2 = coordinates[3];
                    // printf("\nCoordinate pair complete:\n    | (%d,%d) -> (%d,%d)\n", coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
                    if (x1 == x2)
                    {
                        if (y2 > y1)
                        {
                            for (int y = y1; y <= y2; y++)
                            {
                                if (!listContains(list, x1, y))
                                {
                                    push(&list, x1, y);
                                }
                                else if (!listContains(markedList, x1, y))
                                {
                                    push(&markedList, x1, y);
                                    intersections++;
                                }
                            }
                        }
                        else
                        {
                            for (int y = y2; y <= y1; y++)
                            {
                                if (!listContains(list, x1, y))
                                {
                                    push(&list, x1, y);
                                }
                                else if (!listContains(markedList, x1, y))
                                {
                                    push(&markedList, x1, y);
                                    intersections++;
                                }
                            }
                        }
                    }
                    else if (y1 == y2)
                    {
                        if (x2 > x1)
                        {
                            for (int x = x1; x <= x2; x++)
                            {
                                if (!listContains(list, x, y1))
                                {
                                    push(&list, x, y1);
                                }
                                else if (!listContains(markedList, x, y1))
                                {
                                    push(&markedList, x, y1);
                                    intersections++;
                                }
                            }
                        }
                        else
                        {
                            for (int x = x2; x <= x1; x++)
                            {
                                if (!listContains(list, x, y1))
                                {
                                    push(&list, x, y1);
                                }
                                else if (!listContains(markedList, x, y1))
                                {
                                    push(&markedList, x, y1);
                                    intersections++;
                                }
                            }
                        }
                    }
                    coordPairNum = 0;
                }
                else
                {
                    coordPairNum++;
                }
                coordinate = strtok_r(NULL, "  -> ", &contextLine);
            }
        outerIndex++;
        ptr = strtok_r(NULL, "\n", &context);
    }
    return intersections;
}