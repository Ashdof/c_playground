#include "lists.h"
#include <stdlib.h>

/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	struct DuesPayments *head, *ptr, records;
	int nodes;

	/** take inputs from user */
	printf("Date: ");
	scanf("%s", records.date);

	printf("Client: ");
	scanf("%s", records.client);

	printf("Amount: ");
	scanf("%f", &records.amount);

	/* make new node */
        head = constructLinkedList(records, 1);

	/** take new inputs from user */
	printf("Date: ");
	scanf("%s", records.date);

	printf("Client: ");
	scanf("%s", records.client);

	printf("Amount: ");
	scanf("%f", &records.amount);

	/** add new node at the beginning of the linked list */
	ptr = addNewNodeAtBeginning(head, records);

	/* count nodes */
        nodes = countNodes(ptr);

        /* print linked list */
        printLinkedList(ptr, nodes);

	free(ptr);

	return (0);
}
