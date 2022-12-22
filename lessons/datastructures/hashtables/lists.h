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

struct Ht_item
{
	char *key;
	char *value;
};

/**
 * HashTable - define a hash table
 *
 * Description: this struct defines hash table
 */

struct HashTable
{
	struct Ht_item **items;	/* a reference pointer to the items */
	int size;		/* size of the hash table */
	int count;		/* number of elements in the hash table */
};


/* list of prototypes */

void free_item(struct Ht_item *item);
void free_table(struct HashTable *table);
struct HashTable *create_table(int size);
unsigned long int hash_func(char *_str);
struct Ht_item *create_item(char *key_item, char *value_item);

#endif /* LISTS_H */ 
