#include <stdio.h>

/**
 * cardata - a structure declaration
 *
 * Description: this structure declaration defines a typical vehicle
 * at a sales plant
 */

struct car
{
	float tank_capacity;
	int seat_capacity;
	float city_mileage;
	float price;
};

/**
 * main - the starting point of program execution
 *
 * Description: this function invokes the structure to compile data
 * about typical vehicles. It uses arrays to define multiple car
 * brands
 *
 * Return: void
 */

int main(void)
{
	struct car vehicle[2];
	int i;

	for (i = 0; i < 2; i++)
	{
		printf("Fuel capacity - car %d: ", i+1);
		scanf("%f", &vehicle[i].tank_capacity);

		printf("Seat capacity - car %d: ", i+1);
		scanf("%d", &vehicle[i].seat_capacity);

		printf("Auto mileage - car %d: ", i+1);
		scanf("%f", &vehicle[i].city_mileage);

		printf("Price - car %d: ", i+1);
		scanf("%f", &vehicle[i].price);
	}

	/** print information in the array */
	for (i = 0; i < 2; i++)
	{
		printf("\nFuel capacity: \t%f\n", vehicle[i].tank_capacity);
		printf("Seat capacity: \t%d\n", vehicle[i].seat_capacity);
		printf("Auto mileage: \t%f\n", vehicle[i].city_mileage);
		printf("Price: \t\t%3.2f\n", vehicle[i].price);
	}

	return (0);
}
