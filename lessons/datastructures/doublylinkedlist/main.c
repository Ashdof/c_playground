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
	int year, year1;

	head = createNewNode(head, 1990);
	
	printf("Current data in node: %d\n", 1990);
	
	printf("Enter previous year: ");
	scanf("%d", &year);

	printf("Enter next year: ");
	scanf("%d", &year1);

	head = addNewNodeAtBeginning(head, year);
	head = addNewNodeAtEnd(head, year1);
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
