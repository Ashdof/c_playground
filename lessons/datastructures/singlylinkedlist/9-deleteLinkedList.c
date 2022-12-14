#include "lists.h"

/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	struct DuesPayments records, *head, *ptr;
	int numOfNodes;

	printf("Date: ");
	scanf("%s", records.date);

	printf("Client: ");
	scanf("%s", records.client);

	printf("Amount: ");
	scanf("%f", &records.amount);
	

	/* make a linked list */
	head = constructLinkedList(records, 3);
	numOfNodes = countNodes(head);

	/* print linked list */
	ptr = head;

	printLinkedList(head, numOfNodes);

	ptr = deleteLinkedList(head);
	if (ptr == NULL)
		printf("\nLinked list deleted successfully!\n");

	free(ptr);

	return (0);
}
