#include <stdio.h>

struct employee
{
	char *name;
	int age;
	double salary;
};

double manager()
{
	struct employee manager;

	manager.age = 27;

	if(manager.age > 30)
		manager.salary = 65000.350;
	else
		manager.salary = 55000.000;

	return manager.salary;
}

int main(void)
{
	struct employee employee1 = {"Jay", 32, 150000.00};
	struct employee employee2 = {"Kay", 35, 750000.6355};

	printf("\nEmployee: \t%s\n", employee1.name);
	printf("Age: \t%d\n", employee1.age);
	printf("Salary: \t%3.2lf\n", employee1.salary);
	printf("\nEmployee: \t%s\n", employee2.name);
	printf("Age: \t%d\n", employee2.age);
	printf("Salary: \t%3.2lf\n", employee2.salary);

	return (0);
}
