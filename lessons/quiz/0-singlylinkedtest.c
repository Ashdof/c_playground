#include "0-linkedtest.h"

void push(struct Records **head, struct StudentData pupil, struct ExamData exams);
struct Records *constructLinkedList(struct Records values, int number);
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
	struct Records records, *head;
	int i = 1;

	/** supply data */
	printf("First name: ");
	scanf("%s", records.studentData.firstName);

	printf("Last name: ");
	scanf("%s", records.studentData.lastName);

	printf("Exam date: ");
	scanf("%s", records.examData.examDate);

	printf("Term: ");
	scanf("%d", &records.examData.termNumber);

	printf("Subject: ");
	scanf("%s", records.examData.subject);

	printf("Score: ");
	scanf("%d", &records.examData.score);

	head = constructLinkedList(records, i);

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
 * @values: data of type struct Records
 * @number: the number of records
 *
 * Description: this struct is a function that constructs a linked
 * list. It is passed data of type struct Records. The Records struct
 * is a complex struct involving the StudentData and the ExamData
 * structs. Each of these structs have data of their respective
 * subjects. The structs are accessed using the dot operator. This
 * function is also passed an integer value, number which is used to
 * determine the number of nodes to create for the linked list. Each
 * node, therefore is a struct of type StudentData and ExamData
 *
 * Return: a reference to the head of the linked list
 */

struct Records *constructLinkedList(struct Records values, int number)
{
	struct Records *head = NULL;
	int i;

	/** start from the end of the array */
	for (i = number - 1; i >= 0; i--)
		push(&head, values.studentData, values.examData);

	return (head);
}


/**
 * printLinkedList - print the contents of a linked list
 * @head: a reference to the head of the linked list
 *
 * Description: this function is passed a pointer to the head of
 * the linked list. It then traverses and prints the contents of
 * the contents of the nodes of the list.
 *
 * Return: void
 */

void printLinkedList(struct Records *head)
{
	struct Records *ptr = head;
	int i;

	for (i = 0; head != NULL; i++)
	{
		printf("\nStudent name: %s %s\n", ptr->studentData.firstName, ptr->studentData.lastName);
		printf("Examination date: %s\n", ptr->examData.examDate);
		printf("Term number: %d\n", ptr->examData.termNumber);
		printf("Examination paper: %s\n", ptr->examData.subject);
		printf("Examination score: %d\n", ptr->examData.score);

		head = head->next;
	}

	printf("End of records\n");
}
