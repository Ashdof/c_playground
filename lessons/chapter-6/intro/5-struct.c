#include <stdio.h>
#include <string.h>

/** define student struct */
struct StudentData
{
	char firstName[30];
	char lastName[30];
	int age;
};

/** define address struct */
struct Address
{
	char country[30];
	char city[30];
	char street[30];
	char postalAddress[30];
	char phone[15];
	char email[20];
};


/** define employee struct */
struct Employee
{
	char fullName[30];
	char profession[30];
	int age;
	struct Address address;
	float salary;
};

int main(void)
{
	struct Employee employee;

	/**
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
	*/
	
	printf("Full name: ");
	scanf("%s", employee.fullName);

	printf("Profession: ");
	scanf("%s", employee.profession);

	printf("Age: ");
	scanf("%d", &(employee.age));

	printf("Salary: ");
	scanf("%f", &(employee.salary));

	printf("Country: ");
	scanf("%s", employee.address.country);

	printf("City: ");
	scanf("%s", employee.address.city);

	printf("Postal address: ");
	scanf("%s", employee.address.postalAddress);

	printf("Phone number: ");
	scanf("%s", employee.address.phone);

	printf("Email address: ");
	scanf("%s", employee.address.email);

	printf("\nEmployee Data:\n");
	printf("Full name: %s\n", employee.fullName);
	printf("Profession: %s\n", employee.profession);
	printf("Age: %d\n", employee.age);
	printf("Salary: %3.2f\n", employee.salary);
	printf("Country: %s\n", employee.address.country);
	printf("City: %s\n", employee.address.city);
	printf("Postal address: %s\n", employee.address.postalAddress);
	printf("Phone number: %s\n", employee.address.phone);
	printf("Email address: %s\n", employee.address.email);

	return (0);
}
