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

void freeLinkedList(struct Node *head);
void printLinkedList(struct Node *head);
struct Node *deleteLastNode(struct Node *head);
struct Node *deleteFirstNode(struct Node *head);

struct Node *createDoublyLinkedList(struct Node *head);
struct Node *createNewNode(struct Node *head, int value);
struct Node *addNewNodeAtEnd(struct Node *head, int value);
struct Node *deleteIntermediateNode(struct Node *head, int n);
struct Node *addNewNodeAtBeginning(struct Node *head, int value);
struct Node *addNewNodeAfterPosition(struct Node *head, int value, int pos);
struct Node *insert_dnodeint_at_index(struct Node **h, unsigned int idx, int n);

#endif /* LISTS_H */
