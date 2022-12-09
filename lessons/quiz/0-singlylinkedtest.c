#include "0-linkedtest.h"

void push(struct Records, struct StudentData studentData, struct ExamData examData);
struct Records *constructLinkedList(struct Records, int);
void printLinkedList(struct Records *head);


/**
 * main - the main function
 *
 * Description: this function is the starting point for the
 * execution of the programme
 *
 * Return: void
 */

int main(void)
{
	struct Student studentData = {"Jay", "Kay", 13};
	struct ExamData examData = {"10-Dec-2022", "Mathematics", 75};
	struct Records records, *head;
	int i, num;

	num = 2;

	records = {studentData, examData};
	head = constructLinkedList(records, num);

	printLinkedList(head);

	return (0);
}

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


/**
 * printLinkedList - print the contents of a linked list
 * @head: a reference to the head of the linked list
 *
 * Description: this function is passed a pointer to the head of
 * the linked list. It then prints the nodes of the list.
 *
 * Return: void
 */

void printLinkedList(struct Records *head)
{
	struct Records *ptr = head;

	while (ptr)
	{
		printf("Student:\n");
		printf("Student name: %s %s\n", ptr->studentData->firstName, ptr->studentData->lastName);

		printf("\nExamination:\n");
		printf("Examination date: %s\n", ptr->examData->examDate);
		printf("Term number: %d\n", ptr->examData->termNumber);
		printf("Examination paper: %s\n", ptr->examData->subject);
		printf("Examination score: %d\n", ptr->examData->score);
	}

	printf("End of records\n");
}
