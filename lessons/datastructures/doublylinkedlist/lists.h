#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};


struct Node *createNewNode(struct Node *head, int value);
struct Node *addNewNodeAtBeginning(struct Node *head, int value);

#endif /* LISTS_H */
