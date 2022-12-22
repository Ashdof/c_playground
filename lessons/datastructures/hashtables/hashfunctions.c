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
