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

hash_table *create_table(int size)
{
	int i;

	hash_table *table = malloc(sizeof(hash_table));
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

void free_table(hash_table *table)
{
	ht_item *item;
	int i;

	for (i = 0; i < table->size; i++)
	{
		item = table->items[i];
		if (item != NULL)
			free(item);
	}

	free(table->items);
	free(table);
}


/**
 * handle_collision - handle collisions in hash table
 * @table: a reference to the hash table
 * @item: a pointer to the item
 *
 * Description:this function handles cases which result in collisions
 * in a hash table
 *
 * Return: void
 */

void handle_collision(hash_table *table, ht_item *item)
{
}


/**
 * insert_table - insert data into hash table
 * @table: a reference to the hash table
 * @key_element: the element used as key
 * @value_element: the element used as value
 *
 * Description: this function inserts a data in the form {key: value}
 * into a hash table
 *
 * Return: 1 on success, or 0 on failure
 */

int insert_table(hash_table *table, char *key_element, char *value_element)
{
	ht_item *item, *cur_item;
       
	/* create a new item */
	item = create_item(key_element, value_element);
	cur_item = table->items[index];

	if (cur_item == NULL) /* key does not exist */
	{
		if (table->count == table->size)  /* table is full */
		{
			printf("InsertError: hash table is full\n");
			return;
		}

		/* insert into table */
		table->items[index] = item;
		table->count++;
	}
	else	/* key exists */
	{
		if (strcmp(cur_item->key, key_element) == 0)
		{
			/* scenario 1: only update values */
			strcpy(table->items[index]->value, value_element);
			return;
		}
		else
		{
			/* scenario 2: handle collision */
			handle_collision(table, item);
			return;

		}
	}

}


/**
 * search_table - search a hash table for an item
 * @table: a pointer to the hash table
 * @key: the key to search for
 *
 * Description: this function searches for a key in a hash table
 * by comparing the index values of key parameter with all the non -
 * NULL keys in the hash table. if index exists, it returns the
 * value, otherise NULL
 *
 * Return: value of searched item or NULL on failure
 */

char *search_table(hash_table *table, char *key)
{
	int index = hash_func(key);
	ht_item *item = table->itens[index];

	/* check all non-NULL items */
	if (item != NULL)
	{
		if (strcmp(item->key, key) == 0)
			return (item->value);
	}

	return (NULL);
}


/**
 * print_search - print a searched item
 * @table: a reference to the table
 * @key: a reference to the key
 *
 * Description: this function prints the item searched for in the
 * hash table
 *
 * Return: void
 */

void print_search(hash_table *table, char *key)
{
	char *val;

	if((val = search_table(table, key)) == NULL)
	{
		printf("Key: %s does not exist\n", key);
		/*return;*/
	}
	else
	{
		printf("Key: %s, Value: %s\n", key, val);
	}
}


/**
 * print_hashTable - print a hash table
 * @table: a reference to the table
 *
 * Description: this function prints out the contents of a hash
 * table
 *
 * Return: void
 */

void print_hashTable(hash_table *table)
{
	printf("\nHash Table\n------------------------------\n");

	for (i = 0; i < table->size; i++)
	{
		if (table->item[i])
			printf("Index: %d, Key: %s, Value: %s\n", i, table->items[i]->key, table->items[i]->value);
	}

	printf("------------------------------\n\n");
}
