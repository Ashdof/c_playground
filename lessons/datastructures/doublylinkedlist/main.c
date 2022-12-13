#include <stdlib.h>
#include "lists.h"


/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	struct Node *ptr, *head = NULL;
	int year;

	head = createNewNode(head, 1990);
	
	printf("Enter year: ");
	scanf("%d", &year);

	head = addNewNodeAtBeginning(head, year);
	ptr = head;

	while (ptr != NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");

	return (0);
}
