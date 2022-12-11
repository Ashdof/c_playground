#include "lists.h"

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
struct DuesPayments *addNodeAtEnd(struct DuesPayments *head, struct DuesPayments values)
{
	struct DuesPayments *temp = malloc(sizeof(struct DuesPayments));

	strcpy(temp->date, values.date);
	strcpy(temp->client, values.client);
	temp->amount = values.amount;
	temp->next = NULL;

	head->next = temp;

	return (temp);
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


/** add a new node at the end of the linked list */
void addNewNodeAtEnd(struct DuesPayments *head, struct DuesPayments values)
{
	struct DuesPayments *newNode = malloc(sizeof(struct DuesPayments));

	strcpy(newNode->date, values.date);
	strcpy(newNode->client, values.client);
	newNode->amount = values.amount;
	newNode->next = NULL;

	head->next = newNode;
}
