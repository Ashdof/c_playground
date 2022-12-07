#include <stdio.h>

struct car
{
	char *brand;
	char *engine;
	char *fuel_type;
	int fuel_tank_capacity;
	int seating_capacity;
	float city_mileage;
};

int main(void)
{
	struct car car1 = {"Benz", "DDis 190 Engine", "Diesel", 75, 5, 35.95};
	struct car car2 = {"Audi", "Kappa Dual Type VTVT", "Petrol", 37, 5, 17.78};

	printf("Car: \t\t%s\n", car1.brand);
	printf("Engine type: \t%s\n", car1.engine);
	printf("Fuel type: \t%s\n", car1.fuel_type);
	printf("Tank capacity: \t%d\n", car1.fuel_tank_capacity);
	printf("Seat capacity: \t%d\n", car1.seating_capacity);
	printf("Auto mileage: \t%f\n", car1.city_mileage);

	printf("\nCar: \t\t%s\n", car2.brand);
	printf("Engine type: \t%s\n", car2.engine);
	printf("Fuel type: \t%s\n", car2.fuel_type);
	printf("Tank capacity: \t%d\n", car2.fuel_tank_capacity);
	printf("Seat capacity: \t%d\n", car2.seating_capacity);
	printf("Auto mileage: \t%f\n", car2.city_mileage);

	return (0);
}
