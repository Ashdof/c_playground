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


/**
 * LinkedList- define a linked list
 *
 * Description: this struct is used to handle collision in a hash
 * table
 */

typedef struct LinkedList
{
	ht_item *item;
	struct LinkedList *next;
}linked_list;

/* list of prototypes */

void free_item(ht_item *item);
void free_table(hash_table *table);
hash_table *create_table(int size);

void print_hashTable(hash_table *table);
unsigned long int hash_func(char *_str);

void print_search(hash_table *table, char *key);
char *search_table(hash_table *table, char *key);

ht_item *create_item(char *key_item, char *value_item);
int insert_table(hash_table *table, char *key_element, char *value_element);

#endif /* LISTS_H */ 
