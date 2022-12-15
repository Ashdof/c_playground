#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	struct Node *head = NULL;
	int idx = 4;

	head = createDoublyLinkedList(head);

	printf("\nBefore deletion:\n");
	printLinkedList(head);

	printf("\nAfter deletion:\n");
	printf("Position to delete node: %d\n", idx);
	head = deleteIntermediateNode(head, idx);
	printLinkedList(head);

	free(head);

	return (0);
}
