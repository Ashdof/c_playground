#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Ht_item - define an item for the hash table
 *
 * Description: this struct defines the elements for the hash
 * table items
 */

typedef struct Ht_item
{
	char *key;
	char *value;
}ht_item;

/**
 * HashTable - define a hash table
 *
 * Description: this struct defines hash table
 */

typedef struct HashTable
{
	struct Ht_item **items;	/* a reference pointer to the items */
	int size;		/* size of the hash table */
	int count;		/* number of elements in the hash table */
}hash_table;


/* list of prototypes */

void free_item(ht_item *item);
void free_table(hash_table *table);
hash_table *create_table(int size);
unsigned long int hash_func(char *_str);
ht_item *create_item(char *key_item, char *value_item);

#endif /* LISTS_H */ 
