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

