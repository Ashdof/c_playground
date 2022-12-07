#include <stdio.h>

void _strncat(char *, char *, int);

/**
 * main - join two strings
 *
 * Description: this programme joins two strings
 *
 * Return: void
 */

int main(void)
{
	char val1[100] = "Something big ";
	char val2[] = "is in me; I can feel him rising.";
	int num = 8;

	printf("Value 1: %s\n", val1);

	_strncat(val1, val2, num);

	printf("Value 2: %s\n", val2);
	printf("Characters to copy: %d\n", num);

	printf("\nCopied: %s\n", val1);

	return (0);
}

/**
 * _strncat - concatenate two strings by a number
 * @s: the receiving string
 * @t: the donating string
 * @n: the number of characters to copy
 *
 * Description: this function copies the characters of string t
 * to string s, by the number indicated by parameter n
 *
 * Return: void
 */

void _strncat(char *s, char *t, int n)
{
	int i;

	for (; *s != '\0'; s++)
		;

	for (i = 0; i < n; i++)
		*s++ = *t++;

	*s++ = '\0';
}
