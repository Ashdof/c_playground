#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DuesPayments
{
	float amount;
	char client[30];
	char date[10];
	struct DuesPayments *next;
};

void push(struct DuesPayments **head, char datePaid[], char clientName[], float amountPaid);
struct DuesPayments *addNodeAtEnd(struct DuesPayments *head, struct DuesPayments values);
int countNodes(struct DuesPayments *head);
void printLinkedList(struct DuesPayments *head);
struct DuesPayments *constructLinkedList(struct DuesPayments values, int number);


/** Main function */

int main(void)
{
	struct DuesPayments *head, records;

	printf("Date: ");
	scanf("%s", records.date);

	printf("Client: ");
	scanf("%s", records.client);

	printf("Amount: ");
	scanf("%f", &records.amount);

	/* make new node */
	head = constructLinkedList(records, 1);

	/* print linked list */
	printLinkedList(head);

	free(head);

	return (0);
}

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
void printLinkedList(struct DuesPayments *head)
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

	printf("End of records\n");
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
