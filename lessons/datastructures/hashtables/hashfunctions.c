#include <string.h>
#include <stdlib.h>
#include "lists.h"

#define CAPACITY 50000  /* size of the hash table */


/**
 * hash_func - compute sum of ascii values
 * @_str: the string parameter
 *
 * Description: this function computes for the sum of the ascii
 * values of a string
 *
 * Return: sum of the values
 */

unsigned long int hash_func(char *_str)
{
        unsigned long int sum = 0;
        int i;

        for (i = 0; _str[i] != '\0'; i++)
                sum += _str[i];

        return sum % CAPACITY;
}


/**
 * create_item - create an item for the hash table
 * @key_item: the element to be used as the key of the hash table
 * @value_item: the element to be used as the value of the hash
 * table
 *
 * Description: this function uses elements passed to it as
 * parameters to create elements for the hash table
 *
 * Return: a pointer to the item or NULL if it fails
 */

ht_item *create_item(char *key_item, char *value_item)
{
	ht_item *item = malloc(sizeof(ht_item));
	if (item == NULL)
		return (NULL);

	item->key = malloc(strlen(key_item + 1));
	if (item->key == NULL)
		return (NULL);

	item->value = malloc(strlen(value_item + 1));
	if (item->value == NULL)
		return (NULL);

	strcpy(item->key, key_item);
	strcpy(item->value, value_item);

	return (item);
}


/**
 * create_table - create a hash table
 * @size: an integer value that denotes the size of the table
 *
 * Description: this function creates a hash table and allocates
 * memory according to the size of the hash table struct and
 * intialise each table value to NULL
 *
 * Return: a pointer to the table or NULL if it fails
 */

hashTable *create_table(int size)
{
	int i;

	hashTable *table = malloc(sizeof(hashTable));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->count = 0;
	table->items = calloc(table->size, sizeof(ht_item));

	if (table->items == NULL)
		return (NULL);

	for (i = 0; i < table->size; i++)
		table->items[i] = NULL;

	return (table);
}


/**
 * free_item - free memory allocated to item
 * @item: a pointer to the item to free its memory
 *
 * Description: this function frees up the memory used by an item
 * after it has been utilised
 *
 * Return: void
 */

void free_item(ht_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}


/**
 * free_table - free memory allocated to the hash table
 * @table: a reference to the table
 *
 * Description: this function frees up the memory used by a hash
 * table
 *
 * Return: void
 */

void free_table(hashTable *table)
{
	int i;

	for (i = 0; i < table->size; i++)
	{
		ht_item *item = table->items[i];
		if (item != NULL)
			free(item);
	}

	free(table->items);
	free(table);
}
