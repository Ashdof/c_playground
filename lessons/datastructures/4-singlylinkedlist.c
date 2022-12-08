#include <stdio.h>
#include<stdlib.h>

#define MAXSIZE 100	/* Maximum character size */

struct Sales
{
	char *item_name;
	float unit_cost;
	int quantity;
	float total_cost;
	struct Sales *next;
};

int main(void)
{
	struct Sales *head = NULL;

	head = malloc(sizeof(struct Sales));

	head->item_name = "A tin of Milk";
	head->unit_cost = 15.50;
	head->quantity = 30;
	head->total_cost = head->unit_cost * head->quantity;
	head->next = NULL;

	printf("Item: %s\n", head->item_name);
	printf("Unit cost: %3.2f\n", head->unit_cost);
	printf("Quantity: %d\n", head->quantity);
	printf("Total cost: %3.2f\n", head->total_cost);

	return (0);
}
