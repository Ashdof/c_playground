#include <stdio.h>

void _strncpy(char *, char *, int n);

/**
 * main - copy from one string to the other
 *
 * Description: this programme invokes a function to copy from
 * one string to the other
 *
 * Return: void
 */

int main(void)
{
	char val1[100];
	char val2[] = "Something big is in me";
	int num = 10;

	_strncpy(val1, val2, num);

	printf("First: %s\n", val2);
	printf("Quantity to copy: %d\n", num);
	printf("Copied: %s\n", val1);

	return (0);
}

/**
 * _strncpy - copy by a number values of one string to the other
 * @s: the receiving string parameter
 * @t: the source string parameter
 * @n: the number of characters to copy
 *
 * Description: this function copies the characters of string t
 * to string s by the number indicated by n
 *
 * Return: void
 */

void _strncpy(char *s, char *t, int n)
{
	int i;

	for (i = 0; i < n; i++)
		*s++ = *t++;

	*s++ = '\0';
}
