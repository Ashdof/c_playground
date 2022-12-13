#include "lists.h"

/**
 * addNewNodeAtBeginning - adds a new node the beginning
 * @head: a reference to the linked list
 * @value: the data to add to the linked list
 *
 * Description: this function adds a new node at the beginning of
 * a doubly linked list
 *
 * Return: a reference to the head of the new linked list
 */

struct Node *addNewNodeAtBeginning(struct Node *head, int value)
{
	struct Node *newNode = malloc(sizeof(struct Node));

	newNode->prev = NULL;
	newNode->data = value;
	newNode->next = NULL;

	newNode->next = head;
	head->prev = newNode;

	head = newNode;

	return (head);
}


/**
 * createNewNode - creates a new node
 * @head: a reference to the first node
 * @value: the value to add to the node
 *
 * Description: this function creates a node with double
 * links or addresses on either sides
 *
 * Return: a reference to the node
 */

struct Node *createNewNode(struct Node *head, int value)
{
	struct Node *newNode = malloc(sizeof(struct Node));

	newNode->prev = NULL;
	newNode->data = value;
	newNode->next = NULL;

	head = newNode;
	return (head);
}
