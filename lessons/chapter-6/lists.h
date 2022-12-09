#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/** define a struct */

struct Years
{
	int year;
	int quantityPurchased;
	int quantitySold;
	struct Years *next;
};

#endif /* LIST_H */
