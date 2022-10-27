#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float celsius(float fahr);
float fahrenheit(float cels);

/**
 * main - teperature conversion program
 *
 * Return: void
 */

int main(void)
{
	int cels;

	printf("%3s %6s\n", "Cels", "Fahrs");
	for (cels = LOWER; cels <= UPPER; cels += STEP)
	{
		printf("%3d %6.2f\n", cels, fahrenheit(cels));
	}

	return (0);
}

/**
 * celsius - converts to celsius
 * @fahr: value in fahrenheit
 *
 * Description: this program converts a given fahrenheit value
 * to degree celsius
 *
 * Return: the converted celsius value
 */

float celsius(float fahr)
{
	float c;

	c = (5.0 / 9.0) * (fahr - 32);

	return (c);
}

/**
 * fahrenheit - converts to fahrenheit
 * @cels: value in degree celsius
 *
 * Description: this program converts a given celsius value to
 * fahrenheits
 *
 * Return: the converted fahrenheit value
 */

float fahrenheit(float cels)
{
	float fahr;

	fahr = (9 / 5) * (cels + 32);

	return (fahr);
}
