#include "lists.h"
#include <stdlib.h>

/** Create a new node */
void push(struct DuesPayments **head, char datePaid[], char clientName[], float amountPaid)
{
	struct DuesPayments *newNode = malloc(sizeof(struct DuesPayments));

	strcpy(newNode->date, datePaid);
	strcpy(newNode->client, clientName);
	newNode->amount = amountPaid;
	newNode->next = *head;

	*head = newNode;
}


/** Add a new node at end of list */
struct DuesPayments *addNewNodeAtEnd(struct DuesPayments **head, struct DuesPayments values)
{
	struct DuesPayments *new, *temp;
       
	new = *head;
	
	temp = malloc(sizeof(struct DuesPayments));
	if (!temp)
		return (NULL);

	strcpy(temp->date, values.date);
	strcpy(temp->client, values.client);
	temp->amount = values.amount;
	temp->next = NULL;

	if (*head == NULL)
	{
		*head = temp;
		return (*head);
	}

	while (new->next)
		new = new->next;

	new->next = temp;

	return (*head);
}


/** add a new node at the beginning of a linked list */
struct DuesPayments *addNewNodeAtBeginning(struct DuesPayments *head, struct DuesPayments values)
{
	struct DuesPayments *newNode = malloc(sizeof(struct DuesPayments));

	strcpy(newNode->date, values.date);
	strcpy(newNode->client, values.client);
	newNode->amount = values.amount;
	newNode->next = NULL;

	newNode->next = head;
	head = newNode;

	return (head);
}

/** add a new node at the beginning of a linked list: version 2 */
void addNodeAtBeginning(struct DuesPayments **head, struct DuesPayments values)
{
	struct DuesPayments *newNode = malloc(sizeof(struct DuesPayments));

	strcpy(newNode->date, values.date);
	strcpy(newNode->client, values.client);
	newNode->amount = values.amount;
	newNode->next = NULL;

	newNode->next = *head;
	*head = newNode;
}


/** add a new node at a given index position */
void addNodeAtGivenIndex(struct DuesPayments *head, struct DuesPayments values, int index)
{
	struct DuesPayments *newNode, *ptr;

	newNode = malloc(sizeof(struct DuesPayments));
	strcpy(newNode->date, values.date);
	strcpy(newNode->client, values.client);
	newNode->amount = values.amount;
	newNode->next = NULL;

	if (index == 0)
	{
		newNode->next = head;
		head = newNode;
	}

	index--;
	while (index != 1)
	{
		ptr = ptr->next;
		index--;
	}

	newNode = ptr->next;
	ptr->next = newNode;
}

/** Count nodes */
int countNodes(struct DuesPayments *head)
{
	int i = 0;

	while (head != NULL)
	{
		i++;
		head = head->next;
	}

	return (i);
}


/** print data in all nodes */
void printLinkedList(struct DuesPayments *head, int numberOfNodes)
{
	struct DuesPayments *ptr = head;
	int i;

	for (i = 0; head != NULL; i++)
	{
		printf("\nDate: %s\n", ptr->date);
		printf("Client: %s\n", ptr->client);
		printf("Date: %.2f\n", ptr->amount);

		head = head->next;
	}

	printf("\nNumber of records: %d\n", numberOfNodes);

	printf("\nEnd of records\n");
}


/** construct linked list */
struct DuesPayments *constructLinkedList(struct DuesPayments values, int number)
{
	struct DuesPayments *head = NULL;
	int i;

	for (i = number - 1; i >= 0; i--)
		push(&head, values.date, values.client, values.amount);

	return (head);
}


/**
 * deleteLinkedList - delete a linked list
 * @head: a reference to the linked list
 *
 * Description: this function deletes an entire singly linked list
 *
 * Return: NULL
 */

struct DuesPayments *deleteLinkedList(struct DuesPayments *head)
{
	struct DuesPayments *temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}

	return (head);
}


/**
 * reverseLinkedList - reverses the nodes in a linked list
 * @head: a reference to the linked list
 *
 * Description: this function reverses the nodes in a singly linked
 * list
 *
 * Return: a reference to the reversed linked list
 */

struct DuesPayments *reverseLinkedList(struct DuesPayments *head)
{
	struct DuesPayments *nextNode = NULL;
	struct DuesPayments *prevNode = NULL;

	while (head != NULL)
	{
		nextNode = head->next;
		head->next = prevNode;
		prevNode = head;
		head = nextNode;
	}

	head = prevNode;

	return (head);
}
