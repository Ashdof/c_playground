#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void addNodeAtEnd(struct Node *head, int value);
void printLinkedList(struct Node *head);
struct Node *constructList(int keys[], int n);
void push(struct Node **headRef, int value);
struct Node *addNewNodeAtEnd(struct Node *ptr, int value);

int main(void)
{
	struct Node *head;
	struct Node *ptr;
	int dateData, i = 0;

	head = malloc(sizeof(struct Node));
	head->data = 1980;
	head->next = NULL;

	ptr = head;

	ptr = addNewNodeAtEnd(ptr, 1985);
	ptr = addNewNodeAtEnd(ptr, 1990);
	ptr = addNewNodeAtEnd(ptr, 1995);
	ptr = addNewNodeAtEnd(ptr, 2000);
	ptr = addNewNodeAtEnd(ptr, 2005);
	ptr = addNewNodeAtEnd(ptr, 2010);
	ptr = addNewNodeAtEnd(ptr, 2015);
	ptr = addNewNodeAtEnd(ptr, 2020);

	ptr = head;

	while (ptr != NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");

	/**
	int values[] = {1990, 1995, 2000, 2005, 2010};
	int num = sizeof(values) / sizeof(values[0]);

	int newVal;

	printf("New value: ");
	scanf("%d", &newVal);

	struct Node *head = constructList(values, num);
	addNodeAtEnd(head, newVal);
	
	printLinkedList(ptr);
	*/

	free(ptr);

	return (0);
}



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



struct Node *constructList(int keys[], int n)
{
	struct Node *head = NULL;
	int i;

	/** start from the last element in the array */
	for (i = n - 1; i >= 0; i--)
		push(&head, keys[i]);

	return (head);
}


void printLinkedList(struct Node *head)
{
	struct Node *ptr = head;

	while (ptr != NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}


/** insert a new node at the end */
void addNodeAtEnd(struct Node *head, int value)
{
	struct Node *ptr, *temp;

	ptr = head;
	temp = malloc(sizeof(struct Node));

	temp->data = value;
	temp->next = NULL;

	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = temp;
}

/** insert a new node at the end, version 2 */
struct Node *addNewNodeAtEnd(struct Node *ptr, int value)
{
	struct Node *temp = malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;

	ptr->next = temp;

	return (ptr);
}
