#include <stdio.h>
#include <stdlib.h>

/**
 * Node - a node structure
 *
 * Description: this is a data structure to store a linked list node
 */

struct Node
{
	int data;
	struct Node *next;
};

/**
 * push - create a new link with the data
 * @headRef: reference pointer to the head of the linked list
 * @value: the data to store in the node
 *
 * Description: this function takes a list and a data value, creates
 * a new link with the given data and pushes it onto the list's front
 * Its head pointer does not pass in the list. Instead, the list is
 * passed in as a 'reference' pointer to the head pointer — this
 * allows us to modify the caller's memory.
 *
 * Return: a reference to the first node of the linked list
 */

void push(struct Node **headRef, int value)
{
	/** allocate memory to the new node and set its size */
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = value;

	/** set the '.next' pointer of the new node to point to the
	 * current first node of the list */
	newNode->next = *headRef;

	/** change head pointer to point to the new node so that
	 * it is now the head of the list */
	*headRef = newNode;
}

/**
 * constructList - create a linked list
 * @key: an array of data to construct the link list
 * @n: the number of data elements to store in the list
 *
 * Description: this function creates a linked list with the
 * data in the array. It creates nodes to the number specified
 * by 'n'. It uses the nodes created by 'push()' function and creates
 * a link to the next node
 *
 * Return: a reference to the head of the linked list
 */

struct Node *constructList(int keys[], int n)
{
	struct Node *head = NULL;
	int i;

	for (i = n - 1; i >= 0; i--)
		push(&head, keys[i]);

	return (head);
}

/**
 * printList - print a linked list
 * @head: a reference to the head of the linked list
 *
 * Description: this function prints the nodes of a linked list
 *
 * Return: void
 */

void printList(struct Node *head)
{
	struct Node *ptr = head;

	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}

/**
 * main - start of programme execution
 *
 * Return: void
 */

int main(void)
{
	int events[] = {1990, 2006, 2009, 2013, 2016, 2022};
	int num = sizeof(events) / sizeof(events[0]);

	/** head points to the first node of the linked list */
	struct Node *head = constructList(events, num);

	/** print the linked list */
	printList(head);

	/*printf("Value of num: sizeof(events) / sizeof(events[0]) - %d\n", num);*/

	return (0);
}
