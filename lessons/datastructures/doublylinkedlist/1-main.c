#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int main(void)
{
	struct Node *head = NULL;
	struct Node *ptr;

	head = createDoublyLinkedList(head);
	ptr = head;

	while (ptr != NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");

	free(ptr);

	return (0);
}
