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
	int val1, val2, val3, val4, val5;

	if (hashTable == NULL)
		printf("Table failed to create ...\n");

	/* insert into table */
	insert_into_table(hashTable, "1", "First address");
	insert_into_table(hashTable, "2", "Second address");
	insert_into_table(hashTable, "3", "Third address");
	insert_into_table(hashTable, "Cau", "Fourth address");
	insert_into_table(hashTable, "Ash", "Fifth address");

	/* print searched items */
	print_search(hashTable, "1");
	print_search(hashTable, "2");
	print_search(hashTable, "3");
	print_search(hashTable, "Cau");
	print_search(hashTable, "Bel");
	print_search(hashTable, "Ash");

	/* print the table */
	print_hashTable(hashTable);

	/* delete items from the table */
	printf("Deleting element of key 1\n");
	ht_delete(hashTable, "1");

	printf("Deleting element of key Cau\n");
    	ht_delete(hashTable, "Cau");
	
	printf("Deleting element of key Bel\n");
	ht_delete(hashTable, "Bel");

	/* print the table */
	print_hashTable(hashTable);
	
	/* free memory allocated to the table */
	free_table(hashTable);
	printf("Memory allocated to table freed successfully.\n");

	return (0);
}
