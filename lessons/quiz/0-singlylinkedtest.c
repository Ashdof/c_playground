#include "4-main.c"

void push(struct Records, struct StudentData studentData, struct ExamData examData);
struct Records *constructLinkedList(struct Records, int);


/**
 * push - create a node
 * @head: a reference pointer to the first node
 * @pupil: a struct of data about a pupil
 * @exams: a struct of data about the examination
 *
 * Description: this function creates a node with a link using
 * data from pupil and exams structs. It then makes the first
 * node as the head
 *
 * Return: void
 */

void push(struct Records **head, struct StudentData pupil, struct ExamData exams)
{
	struct Records *newNode = malloc(sizeof(struct Records));

	newNode->studentData = pupil;
	newNode->examData = exams;
	newNode->next = *head;

	*head = newNode;
}


/**
 * constructLinkedList - construct a linked list
 * @values: an array of type struct Records
 * @number: the number of records
 *
 * Description: this struct is a function that constructs a linked
 * list. It is passed an array of data of type struct and a number
 * which determines the number of nodes to create for the linked list
 *
 * Return: a reference to the head of the linked list
 */

struct Records *constructLinkedList(struct Records values[], int number)
{
	struct Records *head = NULL;
	int i;

	/** start from the end of the array */
	for (i = number - 1; i >= 0; i--)
		push(&head, values[i]);

	return (head);
}
