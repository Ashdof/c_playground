#include <stdio.h>
#include <stdlib.h>

/**
 * Node - a data structure to store a linked list node
 */

struct Node
{
	int data;
	struct Node *next;
};

/**
 * newNode - return new linked list from the heap
 * @data: the node parameter
 *
 * Description: this is a helper function to return a new linked
 * list node from the heap memory
 *
 * Return: a new node
 */

struct Node *newNode(int value)
{
	/** allocate memory to the new node and set its size */
	struct Node *node = malloc(sizeof(struct Node));
	node->data = value;

	/** point the '.next' pointer to Null */
	node->next = NULL;

	/** return the node */
	return node;
}

/**
 * constructList - create linked list
 * 
 * Description: this function creates a linked list of three nodes
 * with data and a link to the next node using the node created by
 * 'newNode' function
 *
 * Return: the head of the linked list
 */

struct Node *constructList()
{
	/** construct list nodes */
	struct Node *first = newNode(1990);
	struct Node *sec = newNode(2006);
	struct Node *third = newNode(2009);
	struct Node *fourth = newNode(2013);
	
	/** rearrange the nodes to create a linked list */
	struct Node *head = first;
	first->next = sec;
	sec->next = third;
	third->next = fourth;

	/** return a pointer to the first node in linked list */
	return head;
}

/**
 * printList - print a linked list
 * @head: a pointer to the head of the linked list to print
 *
 * Description: this function prints out a linked list
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
 * main - starting point for programme execution
 *
 * Return: void
 */

int main(void)
{
	/** point to the first node of the linked list */
	struct Node *head = constructList();

	/** print the list */
	printList(head);

	return (0);
}
