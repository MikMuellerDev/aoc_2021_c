#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "list.h"

void printList(node *head)
{
    node *temp = head;
    // int count = 0;
    printf("[");
    while (temp != NULL)
    {
        printf("(%d|%d)", temp->x, temp->y);
        temp = temp->next;
        if (temp != NULL)
        {
            printf(",");
        }
    }
    printf("]\n");
}

int length(node *head)
{
    int length = 0;
    node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        if (temp != NULL)
        {
            length++;
        }
    }
    return length;
}

bool listContains(node *head, int x, int y)
{
    int len = length(head);
    int currentIndex = 0;
    node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        if (temp != NULL)
        {
            if (temp->x == x && temp->y == y)
            {
                return true;
            }
            currentIndex++;
        }
    }
    return false;
}

node *get(node *head, int index)
{
    int len = length(head);
    int currentIndex = 0;
    node *temp = head;

    if (index >= len)
    {
        printf("Index out of bounds.");
        return head;
    }

    while (temp != NULL)
    {
        temp = temp->next;
        if (temp != NULL)
        {
            currentIndex++;
            if (currentIndex == index)
            {
                return temp;
            }
        }
    }
}

int getX(node *head, int index)
{
    node *temp = head;
    int len = length(head);
    int current = 0;

    if (index >= len)
    {
        printf("Index out of bounds.");
        return head;
    }

    while (temp != NULL)
    {
        if (current == index)
        {
            return temp->x;
        }

        temp = temp->next;
        // if (temp != NULL)
        // {

        // }
        current++;
    }
}

int getY(node *head, int index)
{
    // int len = length(head);
    // int currentIndex = 0;
    // node *temp = head;

    // if (index >= len)
    // {
    //     printf("Index out of bounds.");
    //     return head;
    // }

    // while (temp != NULL)
    // {
    //     temp = temp->next;
    //     if (temp != NULL)
    //     {
    //         currentIndex++;
    //         if (currentIndex == index)
    //         {
    //             return temp->y;
    //         }
    //     }
    // }

    node *temp = head;
    int len = length(head);
    int current = 0;

    if (index >= len)
    {
        printf("Index out of bounds.");
        return head;
    }

    while (temp != NULL)
    {
        if (current == index)
        {
            return temp->y;
        }

        temp = temp->next;
        // if (temp != NULL)
        // {

        // }
        current++;
    }
}

node *createNode(int x, int y)
{
    node *temp = malloc(sizeof(node));
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    return temp;
}

bool isEmpty(node *head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len > 0;
}

void push(node **head, int x, int y)
{
    if (*head == NULL)
    {
        *head = createNode(x, y);
    }
    else
    {
        node *temp;
        temp = createNode(x, y);
        temp->next = *head;
        *head = temp;
    }
}

node *pop(node **head)
{
    if (isEmpty(*head) == 1)
    {
        node *temp = malloc(sizeof(node));
        temp = *head;
        *head = temp->next;
        free(temp);
        return *head;
    }
    return 0;
}