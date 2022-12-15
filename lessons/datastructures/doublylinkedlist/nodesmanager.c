#include "lists.h"
#include <stdlib.h>


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

	struct Node *newNode = createNewNode(head, value);
	
	newNode->next = head;
	head->prev = newNode;

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

	newNode = createNewNode(head, value);

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


/**
 * createDoublyLinkedList - create an entire doubly linked list
 * @head: a reference to the linked list
 *
 * Description: this function creates an entire linked list
 *
 * Return: a reference to the first node of the linked list
 */

struct Node *createDoublyLinkedList(struct Node *head)
{
	int numOfNodes, value, i;

	printf("Number of nodes to create: ");
	scanf("%d", &numOfNodes);

	if (numOfNodes == 0)
		return (head);

	printf("Value for node 1: ");
	scanf("%d", &value);
	head = createNewNode(head, value);

	for (i = 1; i < numOfNodes; i++)
	{
		printf("Enter value %d: ", i+1);
		scanf("%d", &value);
		head = addNewNodeAtEnd(head, value);
	}

	return (head);
}


/**
 * deleteFirstNode - deletes the first node
 * @head: a reference to the first node of the list
 *
 * Description: this function deletes the first node of the linked
 * list
 *
 * Return: a reference pointer to the new linked list
 */

struct Node *deleteFirstNode(struct Node *head)
{
	struct Node *ptr = head;
	head = head->next;
	free(ptr);
	head->prev = NULL;

	return (head);
}


/**
 * printLinkedList - print a linked list
 * @head: a reference to the first node of the linked list
 *
 * Description: this function prints all the elements of a doubly
 * linked list
 *
 * Return: void
 */

void printLinkedList(struct Node *head)
{
	struct Node *ptr = head;

	while (ptr != NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}


/**
 * deleteLastNode - delete the last node
 * @head: a reference to the first node of the linked list
 *
 * Description: this function deletes the last node of the linked
 * list
 *
 * Return: a reference to the new linked list
 */

struct Node *deleteLastNode(struct Node *head)
{
	struct Node *ptr, *temp;

	ptr = head;
	while(ptr->next != NULL)
		ptr = ptr->next;

	temp = ptr->prev;
	temp->next = NULL;
	free(ptr);
	ptr = NULL;

	return (head);
}
