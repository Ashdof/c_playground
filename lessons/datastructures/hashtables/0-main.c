#include "lists.h"

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
