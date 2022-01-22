#include <stdbool.h>
#ifndef LIST_H
#define LIST_H

struct listNode
{
    int x;
    int y;
    struct listNode *next;
};
typedef struct listNode node;

node *createNode(int x, int y);
void printList(node *head);
int length(node *head);
node *get(node *head, int index);
int getX(node *head, int index);
int getY(node *head, int index);
bool isEmpty(node *head);
bool listContains(node *head, int x, int y);
void push(node **head, int x, int y);
node *pop(node **head);

#endif