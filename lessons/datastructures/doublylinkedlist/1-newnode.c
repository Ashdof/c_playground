#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};


struct Node *createNewNode(struct Node *head, int value);


/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	struct Node *temp = NULL;
	int year;

	printf("Enter year: ");
	scanf("%d", &year);

	temp = createNewNode(temp, year);

	printf("Node:\n %d\n", temp->data);

	return (0);
}

/**
 * createNewNode - creates a new node
 * @head: a reference to the first node
 * @value: the value to add to the node
 *
 * Description: this function creates a node with double
 * links or addresses on either sides
 *
 * Return: a reference to the node
 */

struct Node *createNewNode(struct Node *head, int value)
{
	struct Node *newNode = malloc(sizeof(struct Node));

	newNode->prev = NULL;
	newNode->data = value;
	newNode->next = NULL;

	head = newNode;
	return (head);
}
