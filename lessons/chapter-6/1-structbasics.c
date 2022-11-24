#include <stdio.h>
#include <math.h>

/**
 * point - a structure declaration
 *
 * Description: this is a simple structure declaration
 *
 * Return: nothing
 */

struct point
{
	int x;
	int y;
};

/**
 * main - test the structure
 *
 * Description: this program uses a simple structure definition
 * to compute the distance between two points
 *
 * Return: void
 */

int main(void)
{
	struct point pt = {320, 200};
	double dist, sqrt(double);

	dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);

	printf("Total distance: %6.2f\n", dist);

	return (0);
}
