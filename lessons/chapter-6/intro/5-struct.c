#include <stdio.h>
#include <string.h>

/** define student struct */
struct StudentData
{
	char firstName[30];
	char lastName[30];
	int age;
};


/** define employee struct */
struct Employee
{
	float salary;
	int age;
	char fullName[30];
	char profession[30];
};

int main(void)
{
	struct Employee employee[2];
	int i;

	for (i = 0; i < 2; i++)
	{

		printf("Full name: ");
		scanf("%s", employee[i].fullName);

		printf("Profession: ");
		scanf("%s", employee[i].profession);

		printf("Age: ");
		scanf("%d", &(employee[i].age));

		printf("Salary: ");
		scanf("%f", &(employee[i].salary));
	}

	printf("\nEmployee Data:\n");
	for (i = 0; i < 2; i++)
	{
		printf("\nFull name: %s\n", employee[i].fullName);
		printf("Profession: %s\n", employee[i].profession);
		printf("Age: %d\n", employee[i].age);
		printf("Salary: %3.2f\n", employee[i].salary);
	}

	/*
	printf("Full name: ");
	scanf("%s", employee.fullName);

	printf("Profession: ");
	scanf("%s", employee.profession);

	printf("Age: ");
	scanf("%d", &(employee.age));

	printf("Salary: ");
	scanf("%f", &(employee.salary));

	struct StudentData studentData;

	printf("First name: ");
	scanf("%s", studentData.firstName);

	printf("Last name: ");
	scanf("%s", studentData.lastName);

	printf("Student age: ");
	scanf("%d", &studentData.age);

	strcpy(studentData.firstName, "Jay");
	strcpy(studentData.lastName, "Kay");
	studentData.age = 15;

	printf("\nEmployee Data:\n");
	printf("Full name: %s\n", employee.fullName);
	printf("Profession: %s\n", employee.profession);
	printf("Age: %d\n", employee.age);
	printf("Salary: %3.2f\n", employee.salary);
	*/

	return (0);
}
