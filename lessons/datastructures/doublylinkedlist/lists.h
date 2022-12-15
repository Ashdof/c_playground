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


struct Node *createDoublyLinkedList(struct Node *head);
struct Node *createNewNode(struct Node *head, int value);
struct Node *addNewNodeAtEnd(struct Node *head, int value);
struct Node *addNewNodeAtBeginning(struct Node *head, int value);
struct Node *addNewNodeAfterPosition(struct Node *head, int value, int pos);

#endif /* LISTS_H */
