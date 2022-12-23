#include "lists.h"

#define CAPACITY 50000  /* size of the hash table */

/**
 * mian - test the code
 *
 * Return: 0 on success
 */

int main(void)
{
	hash_table *hashTable = create_table(CAPACITY);

	if (hashTable == NULL)
		printf("Table failed to create ...\n");

	/* insert into table */
	insert_table(hashTable, "1", "First address");
	insert_table(hashTable, "2", "Second address");
	insert_table(hashTable, "3", "Third address");
	insert_table(hashTable, "Cau", "Fourth address");
	insert_table(hashTable, "Hel", "Fifth address");

	/* print searched items */
	print_search(hashTable, "1");
	print_search(hashTable, "2");
	print_search(hashTable, "3");
	print_search(hashTable, "Cau");
	print_search(hashTable, "Hel");
	print_search(hashTable, "Ash");

	/* print the table */
	print_hashTable(hashTable);

	/* free memory allocated to the table */
	free_table(hashTable);
	printf("Memory allocated to table freed successfully.\n");

	return (0);
}
