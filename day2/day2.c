#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day2.h"
#include "../file/file.h"

void Run2()
{
    char *string;
    string = (char *)malloc(20001);
    strcpy(string, read_file("./day2/input.txt"));

    printf("Part1 --> Product of coordinates: %d\n", Part21(string));
    printf("Part2 --> Product of coordinates: %d\n", Part22(string));
    free(string);
}

int Part21(char *inputString)
{
    char *string;
    string = (char *)malloc(20001);
    strcpy(string, inputString);

    int init_size = strlen(string);
    char *ptr = strtok(string, "\n");
    char *rawInstruction;
    rawInstruction = (char *)malloc(10);
    int instructionIndex = 0;
    // Actual Instruction
    char *instruction;
    instruction = (char *)malloc(10);
    int instructionValue;

    // Saved depth and X value
    int posX = 0;
    int posY = 0;

    while (ptr != NULL)
    {
        strcpy(rawInstruction, ptr);
        char *context = NULL;
        char *instructionPointer = strtok_r(rawInstruction, " ", &context);
        while (instructionPointer != NULL)
        {
            if (instructionIndex == 2)
            {
                instructionIndex = 0;
            }

            if (instructionIndex == 0)
            {
                strcpy(instruction, instructionPointer);
            }
            else if (instructionIndex == 1)
            {
                instructionValue = atoi(instructionPointer);
            }
            instructionPointer = strtok_r(NULL, " ", &context);
            instructionIndex++;
        }

        // Now the complete instruction can be used / parsed
        if (instructionIndex == 2)
        {
            if (strcmp(instruction, "down") == 0)
            {
                posY += instructionValue;
            }
            else if (strcmp(instruction, "up") == 0)
            {
                posY -= instructionValue;
            }
            else if (strcmp(instruction, "forward") == 0)
            {
                posX += instructionValue;
            }
        }

        ptr = strtok(NULL, "\n");
    }

    return posX * posY;
}

int Part22(char *string)
{
    int init_size = strlen(string);
    char *ptr = strtok(string, "\n");
    char *rawInstruction;
    rawInstruction = (char *)malloc(10);
    int instructionIndex = 0;
    // Actual Instruction
    char *instruction;
    instruction = (char *)malloc(10);
    int instructionValue;

    // Saved depth and X value
    int posX = 0;
    int posY = 0;
    int aim = 0;

    while (ptr != NULL)
    {
        strcpy(rawInstruction, ptr);
        char *context = NULL;
        char *instructionPointer = strtok_r(rawInstruction, " ", &context);
        while (instructionPointer != NULL)
        {
            if (instructionIndex == 2)
            {
                instructionIndex = 0;
            }

            if (instructionIndex == 0)
            {
                strcpy(instruction, instructionPointer);
            }
            else if (instructionIndex == 1)
            {
                instructionValue = atoi(instructionPointer);
            }
            instructionPointer = strtok_r(NULL, " ", &context);
            instructionIndex++;
        }

        // Now the complete instruction can be used / parsed
        if (instructionIndex == 2)
        {
            if (strcmp(instruction, "down") == 0)
            {
                aim += instructionValue;
            }
            else if (strcmp(instruction, "up") == 0)
            {
                aim -= instructionValue;
            }
            else if (strcmp(instruction, "forward") == 0)
            {
                posX += instructionValue;
                posY += aim * instructionValue;
            }
        }

        ptr = strtok(NULL, "\n");
    }
    return posX * posY;
}