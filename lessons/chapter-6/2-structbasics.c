#include <stdio.h>
#define XMAX 320
#define YMAX 200

struct point makepoint(int, int);

struct point
{
	int x;
	int y;
};

struct rect
{
	struct point pt1;
	struct point pt2;
};

/**
 * main - main function
 *
 * Return: void
 */

int main(void)
{
	int val1, val2;
	struct point origin, *p;

	printf("Enter origin-x value: ");
	scanf("%d", &val1);

	printf("Enter origin-y value: ");
	scanf("%d", &val2);

	origin = makepoint(val1, val2);
	p = &origin;

	printf("Origin is (%d, %d)\n", (*p).x, (*p).y);

	return (0);
}

/**
 * makepoint - a structure to make a point
 *
 * Description: this function is a structure that makes a point from
 * x and y components
 *
 * Return: a point structure
 */

struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;

	return temp;
}

/**
 * addpoint - add two points
 *
 * Description: this function adds two points
 *
 * Return: the result of the addition
 */

struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;

	return (p1);
}
