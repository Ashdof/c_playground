#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100	/* maximum limit of a stack */

/* Global variables */
int stack[LIMIT];	/* an array of a stack */
int top;		/* variable to operate on a stack */
int i;			/* control variable to loop through a stack */
int choice;		/* to decide on operation to perform */

void push();
void pop();
void display();


/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	printf("Data Structure Lessons\n\n");
	
	printf("ARRAY IMPLEMENTATION USING STACK\n\n");

	top = -1;
	do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		printf("Your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid choice!\n");
				break;
		}

	} while (choice != 4);

	return (0);
}

/**
 * push - add an element to a stack
 *
 * Description: this function adds an element to the top of a stack
 */

void push()
{
	int value;

	if (top == LIMIT -1)
	{
		printf("Stack overlow\n");
	}
	else
	{
		printf("Enter value: ");
		scanf("%d", &value);
		top++;
		stack[top] = value;
	}
}


/**
 * pop - delete an element from a stack
 *
 * Description: this function adds an elemet to the top of a stack
 */

void pop()
{
	int value;

	if (top == -1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		value = stack[top];
		printf("The deleted value: %d\n", value);
		top--;
	}
}


/**
 * display - display all elements in a stack
 *
 * Description: this function prints out all the elements in a stack
 */

void display()
{
	if (top == -1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		printf("Values in the stack are:\n");
		for (i = top; i >= 0; i--)
			printf("Value: %d\n", stack[i]);
	}
}
