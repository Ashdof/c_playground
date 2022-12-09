#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/** define a struct */

struct Records
{
	int year;
	struct Records *next;
};

#endif /* LIST_H */
