#include "lists.h"

/**
 * mian - test the code
 *
 * Return: 0 on success
 */

int main(void)
{
	struct Ht_item *item_idx;
	char *day, *animal;

	day = "Monday";
	animal = "Dog";

	item_idx = create_item(day, animal);

	if (item_idx == NULL)
		printf("[%s] item failed to create ...\n", day);
	else
		printf("[%s] item created successfully ...\n", day);

	free_item(item_idx);
	printf("Memory allocated to [%s] freed successfully.\n", day);

	return (0);
}
