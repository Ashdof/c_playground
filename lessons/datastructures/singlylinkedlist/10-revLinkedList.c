#include "lists.h"
#include <stdlib.h>

/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	struct DuesPayments rec, rec1, rec2, *head, *ptr, *temp;
	int numOfNodes;

	printf("Date 1: ");
	scanf("%s", rec.date);

	printf("Client 1: ");
	scanf("%s", rec.client);

	printf("Amount 2: ");
	scanf("%f", &rec.amount);

	head = constructLinkedList(rec, 1);

	printf("Date 2: ");
	scanf("%s", rec1.date);

	printf("Client 2: ");
	scanf("%s", rec1.client);

	printf("Amount 2: ");
	scanf("%f", &rec1.amount);

	head = addNewNodeAtEnd(&head, rec1);

	printf("Date 3: ");
	scanf("%s", rec2.date);

	printf("Client 3: ");
	scanf("%s", rec2.client);

	printf("Amount 3: ");
	scanf("%f", &rec2.amount);

	head = addNewNodeAtEnd(&head, rec2);
	numOfNodes = countNodes(head);

	printLinkedList(head, numOfNodes);

	printf("\n\nThe Reversed Nodes\n");

	head = reverseLinkedList(head);
	printLinkedList(head, numOfNodes);

	return (0);
}
