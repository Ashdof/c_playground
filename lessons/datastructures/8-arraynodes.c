#include <stdio.h>


void addNewDataAtPosition(int arr[], int arr2[], int n, int data, int pos);


/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	int arr[] = {2, 34, 21, 6, 7, 8, 90, 67, 23, 39};
	int i, pos = 5, data = 78;
	int size = sizeof(arr) / sizeof(arr[0]);
	int arr2[size + 1];

	addNewDataAtPosition(arr, arr2, size, data, pos);

	/** print the new array */
	printf("Old array data\n");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);

	printf("\n");

	printf("\nNew Array Data\n");
	for (i = 0; i < size + 1; i++)
		printf("%d ", arr2[i]);

	printf("\n");
	return (0);
}

/**
 * addNewDataAtPosition - add data at a given position
 * @arr: the old array data
 * @arr2: the new array to receive copies of values from the
 * old array
 * @n: the size of the old array
 * @data: the data value to add to the array at the given position
 * @pos: the given index position at which the new data will be
 * added
 *
 * Description: this function adds a new data at a given position
 * of an array. It copies data from the old array (arr) to the new
 * array(arr2) up to the given index position, adds the data to be
 * added and then copies the remaining data from the old array to
 * the new array.
 *
 * Return: void
 */

void addNewDataAtPosition(int arr[], int arr2[], int n, int data, int pos)
{
	int i;
	int index = pos - 1;
	for (i = 0; i < index - 1; i++)
		arr2[i] = arr[i];

	arr2[index] = data;
	
	int j;
	for (i = 5, j = 4; i < 11, j < 10; i++, j++)
		arr2[i] = arr[j];
}
