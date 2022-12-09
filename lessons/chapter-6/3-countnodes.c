#include "lists.h"

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
