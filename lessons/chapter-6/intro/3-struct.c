#include <stdio.h>

/**
 * abc - a structure declaration
 */

struct abc
{
	int x;
	int y;
	int z;
};

/**
 * main - test the structure
 *
 * Description: this function tests the structure by using the
 * designated initialisation technique to initialise structure
 * variables
 *
 * Return: void
 */

int main(void)
{
	struct abc a = {.y = 20, .x = 10, .z = 30};

	printf("%d %d %d\n", a.x, a.y, a.z);

	return (0);
}
