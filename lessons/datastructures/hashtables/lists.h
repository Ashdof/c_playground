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
	linked_list **overflow_bucket;
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
linked_list allocate_memory();
void free_item(ht_item *item);
void free_table(hash_table *table);
hash_table *create_table(int size);
ht_item *pop_node(linked_list *head);
void print_hashTable(hash_table *table);
unsigned long int hash_func(char *_str);
void free_linked_list(linked_list *head);

linked_list *create_new_node(ht_item *item);
void free_overflow_buckets(hash_table *table);
void print_search(hash_table *table, char *key);
char *search_table(hash_table *table, char *key);

ht_item *create_item(char *key_item, char *value_item);
linked_list **create_overflow_bucket(hash_table *table);
linked_list insert_into_linkedlist(linked_list *head, ht_item *item);
int insert_table(hash_table *table, char *key_element, char *value_element);

#endif /* LISTS_H */ 
