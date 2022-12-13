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


/**
 * addNewNodeAtEnd - add a new node
 * @head: a reference to the linked list
 * @value: the data to add to the node
 *
 * Description: this function adds a new node at the end of
 * a doubly linked list
 *
 * Return: a reference to the new linked list
 */

struct Node *addNewNodeAtEnd(struct Node *head, int value)
{
	struct Node *newNode, *temp;
       
	newNode = malloc(sizeof(struct Node));

	newNode->prev = NULL;
	newNode->data = value;
	newNode->next = NULL;

	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;
	newNode->prev = temp;

	return (head);
}


/**
 * addNewNodeAfterPosition - add a new node
 * @head: a reference to the linked list
 * @value: the data to add to the node
 * @position: the index to add the new node to the linked list
 *
 * Description: this function adds a new node after a given index
 * position of a doubly linked list
 *
 * Return: a reference to the new doubly linked list
 */

struct Node *addNewNodeAfterPosition(struct Node *head, int value, int pos)
{
	struct Node *newNode, *temp, *temp2;

	temp = head;
	newNode = temp2 = NULL;

	newNode = createNewNode(head, value);

	while (pos != 1)
	{
		temp = temp->next;
		pos--;
	}

	if (temp->next == NULL)
	{
		temp->next = newNode;
		newNode = temp;
	}
	else
	{
		temp2 = temp->next;
		temp->next = newNode;
		temp2->prev = newNode;
		newNode->next = temp2;
		temp2->prev = temp;
	}

	return (head);
}