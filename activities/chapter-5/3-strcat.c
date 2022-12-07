#include <stdio.h>

void _strcat(char *s, char *t);

/**
 * main - join two strings
 *
 * Description: this program takes two strings and joins the
 * second string to the end of the first string
 *
 * Return: void
 */

int main(void)
{
	char fname[100] = "Emmanuel ";
	char lname[] = "Enchill";

	_strcat(fname, lname);

	printf("Full name: %s\n", fname);

	return (0);
}

/**
 * _strcat: concatenate two strings
 * @s: the destination string
 * @t: the source string
 *
 * Description: this functions joins the second parameter to the
 * end of the first parameter
 *
 * Return: void
 */

void _strcat(char *s, char *t)
{
	for (; *s != '\0'; s++)
		;

	while ((*s++ = *t++) != '\0')
		;
}
