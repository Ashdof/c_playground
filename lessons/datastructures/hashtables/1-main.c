#include "lists.h"

/**
 * mian - test the code
 *
 * Return: 0 on success
 */

int main(void)
{
	ht_item *item_idx;
	hash_table *hashTable;
	int size;
	char *day, *animal;

	day = "Monday";
	animal = "Dog";
	size = 5;

	item_idx = create_item(day, animal);

	if (item_idx == NULL)
		printf("[%s] item failed to create ...\n", day);
	else
		printf("[%s] item created successfully ...\n", day);

	hashTable = create_table(size);

	if (hashTable == NULL)
		printf("[%s] table failed to create ...\n", day);
	else
		printf("[%s] table created successfully ...\n", day);

	free_item(item_idx);
	printf("Memory allocated to [%s] item freed successfully.\n", day);
	
	free_table(hashTable);
	printf("Memory allocated to [%s] table freed successfully.\n", day);

	return (0);
}
