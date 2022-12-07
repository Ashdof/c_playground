#include <stdio.h>

int _strncmp(char *, char *, int);

/**
 * main compare strings
 *
 * Description: this program compares two strings
 *
 * Return: void
 */

int main(void)
{
	char val1[] = "abcdefgh";
	char val2[] = "abcd";
	int rs = _strncmp(val1, val2, 3);

	printf("%d\n", rs);

	/*
	if (rs == 1)
		printf("The first string is bigger than the second\n");
	else if (rs == -1)
		printf("The first string is smaller than the second\n");
	else if (rs == 0)
		printf("The strings are the same\n");
	*/

	return (0);
}

/**
 * _strncmp: compares two strings
 * @s: the first parameter
 * @t: the second parameter
 * @n: the number of characters to compare up to
 *
 * Description: this function compares two given strings character
 * by character up to the specified number
 *
 * Return: 1 if s is greater than t, 0 if they're equal and -1
 * if s is less than t
 */

int _strncmp(char *s, char *t, int n)
{
	for (; *s == *t; s++, t++)
	{
		if (*s == '\0' || n <= 0)
			return (0);
	}

	return (*s - *t);
}
