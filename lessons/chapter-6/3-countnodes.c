#include "lists.h"

void push(struct Years **head, int yr, int qtyPurchased, int qtySold);

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

void push(struct Years **head, int yr, int qtyPurchased, int qtySold)
{
	/** allocate memory */
	struct Years *newNode = malloc(sizeof(struct Years));

	newNode->year = yr;
	newNode->quantityPurchased = qtyPurchased;
	newNode->quantitySold = qtySold;

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

struct Years *makeLinkedList(int values[], int number)
{
	struct Years *head = NULL;
	int i;

	for (i = number - 1; i >= 0; i--)
		push(&head, values[i]);

	return (head);
}
