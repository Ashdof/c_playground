#include <stdio.h>

int addDataAtBeginning(int records[], int len, int value);

/** main function */
int main(void)
{
	int record[10], data = 10, i, n;

	printf("Number of elements: ");
	scanf("%d", &n);
	
	printf("Enter element: ");
	for (i = 0; i < n; i++)
		scanf("%d", &record[i]);

	n = addDataAtBeginning(record, n, data);

	for (i = 0; i < n; i++)
		printf("Value %d: %d\n", i, record[i]);

	return (0);
}


/**
 * addDataAtEnd - add data at the end of an array
 * @records - the array of data
 * @freePos - the empty index position
 * @value: the data to add to the array
 *
 * Description: this function adds a new data to the end of
 * an array of data
 *
 * Return: the array of data
 */

int addDataAtEnd(int records[], int freePos, int value)
{
	records[freePos] = value;
	freePos++;

	return (freePos);
}

/** 
 * addDataAtBeginning - add data at the beginning of an array
 * @records - the array of data
 * @len: the length of the array
 * @value: the data to add to the array
 *
 * Description: this function adds a new data at the beginning
 * of an array
 *
 * Return: the new length of the array
 * */
int addDataAtBeginning(int records[], int len, int value)
{
	int i;
	
	for (i = len - 1; i >= 0; i--)
		records[i+1] = records[i];

	records[0] = value;
	return (len + 1);
}
