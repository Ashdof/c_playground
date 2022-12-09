#include "lists.h"

void push(struct Records **head, int yr);
struct Records *makeLinkedList(int values[], int number);
void printLinkedList(struct Records *head);
int countNodes(struct Records *head);


/**
 * main - the starting point for programme execution
 *
 * Return: void
 */

int main(void)
{
	int years[] = {1990, 1995, 2000, 2005, 2010};
	int i = sizeof(years) / sizeof(years[0]);
	int nodes;
	struct Records *head;

	head = makeLinkedList(years, i);
	nodes = countNodes(head);

	if (nodes == 0)
		printf("Linked list is empty");
	else
		printf("Number of nodes: %d\n", nodes);

	printLinkedList(head);

	return (0);
}


/**
 * push - create a new node with a link
 * @head: a reference pointer to the node
 * @yr: the data to save in the node
 *
 * Description: this function creates a new node with a link
 * using data passed to it via argument
 *
 * Return: void
 */

void push(struct Records **head, int yr)
{
	/** allocate memory */
	struct Records *newNode = malloc(sizeof(struct Records));

	newNode->year = yr;

	newNode->next = *head;
	*head = newNode;
}


/**
 * makeLinkedList - make a linked list
 * @values: an array of data
 * @number: the number of nodes to create in the linked liist
 *
 * Description: this function constructs a linked list using
 * the data supplied via arguments
 *
 * Return: a reference to the head of the linked list
 */

struct Records *makeLinkedList(int values[], int number)
{
	struct Records *head = NULL;
	int i;

	for (i = number - 1; i >= 0; i--)
		push(&head, values[i]);

	return (head);
}


/**
 * printLinkedList - print a linked list
 * @head: a reference to the head of the linked list
 *
 * Description: this function prints the contents of a linked
 * list
 *
 * Return: void
 */

void printLinkedList(struct Records *head)
{
	struct Records *ptr = head;
	int i;
	
	printf("\nData in the linked list nodes\n");
	for (i = 0; head != NULL; i++)
	{
		printf("%d -> ", ptr->year);
		head = head->next;
	}

	print("\nEnd of records\n");
}


/**
 * countNodes - count the number of nodes
 * @head: a reference to the head of the node
 *
 * Description: this function counts for the number of
 * nodes in the linked list
 *
 * Return: the number of nodes or negative 0 if the list is 
 * empty
 */

int countNodes(struct Records *head)
{
	int count;
	struct Records *ptr = NULL;

	if (head == NULL)
		return (0);

	ptr = head;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}

	return (count);
}
