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

	head = createDoublyLinkedList(head);

	printf("\nBefore deletion:\n");
	printLinkedList(head);

	printf("\nAfter deletion:\n");
	head = deleteFirstNode(head);
	printLinkedList(head);

	free(head);

	return (0);
}
