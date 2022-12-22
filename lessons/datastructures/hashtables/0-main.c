#include <stdio.h>

#define CAPACITY 50000	/* size of the hash table */

unsigned long int hash_func(char *_str);


/**
 * mian - test the code
 *
 * Return: 0 on success
 */

int main(void)
{
	char *word, *asem;
	unsigned long int val1, val2;

	word = "Hel";
	asem = "Cau";

	val1 = hash_func(word);
	val2 = hash_func(asem);

	printf("Hash value of \"%s\": %ld\n", word, val1);
	printf("Hash value of \"%s\": %ld\n", asem, val2);

	return (0);
}


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
