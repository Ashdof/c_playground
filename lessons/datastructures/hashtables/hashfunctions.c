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

	/* create an overflow bucket */
	table->overflow_bucket = create_overflow_bucket(table);

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

	/* free overflow bucket linked list and its items */
	free_overflow_buckets(table);
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

void handle_collision(hash_table *table, unsigned long int index,  ht_item *item)
{
	linked_list *head = table->overflow_bucket[index];

	if (head == NULL)
	{
		/* bucket does not exist so create new one */
		head = allocate_memory();
		head->item = item;
		table->overflow_bucket[index] = head;
	}
	else
	{
		/* insert into linked list */
		table->overflow_bucket[index] = insert_into_linkedlist(head, item);
	}
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
	unsigned long int index = hash_func(key_element);
       
	/* create a new item */
	item = create_item(key_element, value_element);
	if (item == NULL)
		return (0);

	cur_item = table->items[index];

	if (cur_item == NULL) /* key does not exist */
	{
		if (table->count == table->size)  /* table is full */
		{
			printf("InsertError: hash table is full\n");
			free_item(item);
			return (0);
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
			/*return;*/
		}
		else
		{
			/* scenario 2: handle collision */
			handle_collision(table, index, item);
			/*return;*/

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
	ht_item *item = table->items[index];
	linked_list *head = table->overflow_bucket[index];

	/* check all non-NULL items */
	while (item != NULL)
	{
		if (strcmp(item->key, key) == 0)
			return (item->value);

		if (head == NULL)
			return (NULL);

		item = head->item;
		head = head->next;
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
		printf("%s does not exist\n", key);
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

	for (int i = 0; i < table->size; i++)
	{
		if (table->items[i])
		{
			printf("Index: %d, Key: %s, Value: %s\n", i, table->items[i]->key, table->items[i]->value);
			
			if (table->overflow_bucket[i])
			{
				printf("=> Overflow Bucket =>");
				linked_list *head = table->overflow_bucket[i];

				while (head)
				{
					printf("Index: %d, Key: %s, Value: %s\n", i, table->items[i]->key, table->items[i]->value);
					head = head->next;
				}
			}

			printf("\n");
		}
	}

	printf("------------------------------\n\n");
}


/**
 * allocate_memory - allocate memory to a linked list
 *
 * Description: this function allocates memory to a linked list
 *
 * Return: a reference to the allocated memory
 */

static linked_list *allocate_memory()
{
	linked_list *memory = malloc(sizeof(linked_list));
	if (!memory)
	{
		printf("Memory cannot be allocated.\n");
		return (NULL);
	}

	return (memory);
}


/**
 * create_new_node - create a new node
 * @item: a reference to the item to stored in the node
 *
 * Description: this function invokes the allocate_memory() function
 * to allocate memory, creates a new node, add item to it and return
 * a reference to the new node
 *
 * Return: a reference to the newly create node or NULL if it fails
 */

static linked_list *create_new_node(ht_item *item)
{
	linked_list *newNode = allocate_memory();
	if (newNode == NULL)
	{
		printf("New node cannot be created.\n");
		return (NULL);
	}

	newNode->item = item;
	newNode->next = NULL;

	return (newNode);
}

/**
 * insert_into_linkedlist - insert nodes into linked list
 * @head: a reference to the first node of the linked list
 * @item: a reference to the item to insert into the linked
 * list
 *
 * Description: this function inserts an item into a linked
 * list passed to it as parameters. It invokes the create_new_node
 * function by passing the item parameter to it.
 *
 * Return: a reference to the new linked list or NULL if it fails
 */

static linked_list *insert_into_linkedlist(linked_list *head, ht_item *item)
{
	linked_list *newNode, *temp;

	newNode = create_new_node(item);
	
	/* create the list if it does not exist */
	if (!head)
	{
		head = newNode;

		return (head);
	}
	else if (head->next == NULL)	/* work more on this function. Consider situation whereby the next node is not the last node */
	{
		/* the list exists; add the new node to the end of the list*/
		head->next = newNode;

		return (head);
	}

	while (temp->next->next)
		temp = temp->next;

	temp->next = newNode;

	return (head);
}


/**
 * pop_node - remove the first node from the linked list
 * @head: a reference to the first node of the linked list
 *
 * Description: this function removes the first node of the linked
 * list and returns the item of the popped node
 *
 * Return: item of the popped node or NULL if it fails
 */

static ht_item *pop_node(linked_list *head)
{
	if (!head || !head->next)
		return (NULL);

	linked_list *ptr = head->next;
	linked_list *temp = head;

	temp->next = NULL;
	head = ptr;

	ht_item *item = NULL;
	memcpy(temp->item, item, sizeof(ht_item));

	free(temp->item->key);
	free(temp->item->value);
	free(temp->item);
	free(temp);

	return (item);
}


/**
 * free_linked_list - free a singly linked list
 * @head: a reference to the head of the linked list
 *
 * Description: this function frees a linked list and all its
 * elements
 *
 * Return: void
 */

static void free_linked_list(linked_list *head)
{
	linked_list *ptr = head;

	while (head)
	{
		ptr = ptr->next;
		free(ptr->item->key);
		free(ptr->item->value);
		free(ptr->item);
		free(ptr);
	}
}


/**
 * create_overflow_bucket - create an overflow bucket
 * @table: a reference to the hash table
 *
 * Description: this function creates an overflow bucket, an array
 * of linked lists
 *
 * Return: a pointer to the bucket or NULL if it fails
 */

static linked_list **create_overflow_bucket(hash_table *table)
{
	linked_list **buckets = calloc(table->size, sizeof(linked_list));
	if (buckets == NULL)
		return (NULL);

	for (int i = 0; i < table->size; i++)
		buckets[i] = NULL;

	return (buckets);
}


/**
 * free_overflow_bucket - free overflow bucket
 * @table: a reference to the hash table
 *
 * Description: this function frees all overflow buckets
 *
 * Return: void
 */

static void free_overflow_buckets(hash_table *table)
{
	linked_list **buckets = table->overflow_bucket;

	for (int i = 0; i < table->size; i++)
		free_linked_list(buckets[i]);

	free(buckets);
}
