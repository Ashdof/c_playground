#include "lists.h"
#include <stdlib.h>

/** Main function */

int main(void)
{
	struct DuesPayments *head, *ptr, records;
	int nodes;

	printf("Date: ");
	scanf("%s", records.date);

	printf("Client: ");
	scanf("%s", records.client);

	printf("Amount: ");
	scanf("%f", &records.amount);

	/* make new node */
	head = constructLinkedList(records, 1);

	/* take new inputs */
	printf("Date: ");
	scanf("%s", records.date);

	printf("Client: ");
	scanf("%s", records.client);

	printf("Amount: ");
	scanf("%f", &records.amount);

	/* add new node */
	addNewNodeAtEnd(head, records);

	/* count nodes */
	nodes = countNodes(head);

	/* print linked list */
	printLinkedList(head, nodes);

	free(head);

	return (0);
}
