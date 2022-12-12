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
	ptr = addNewNodeAtEnd(&head, records);

	/* count nodes */
	nodes = countNodes(ptr);

	/* print linked list */
	printLinkedList(ptr, nodes);

	free(ptr);

	return (0);
}
