#include <stdio.h>

void tempConversion(char type, float lower, float upper, float step);

/**
 * main - teperature conversion program
 *
 * Return: void
 */

int main(void)
{
	char c;
	float start, end, step;

	while ((c = getchar()) != EOF)
	{
		if (c == 'c' || c == 'C' || c == 'F' || c == 'f')
		{
			printf("Start value: ");
			scanf("%f", &start);

			printf("End value: ");
			scanf("%f", &end);

			printf("Step value: ");
			scanf("%f", &step);

			tempConversion(c, start, end, step);
			break;
		}
		else
		{
			printf("Enter C/c for degree celsius or F/f for fahrenheit\n");
		}
	}

	return (0);
}

/**
 * tempConversion - convert temperature values
 * @type: type of conversion which is denoted by a character, c
 * for celsius and f for fahrenheit
 * @lower: the start value
 * @upper: the ending value
 * @step: the step interval for the conversion
 *
 * Description: this function converts temperature value from either
 * degree celsius to fahrenheit or the other way around depending on
 * values provided.
 *
 * Return: nothing
 */

void tempConversion(char type, float lower, float upper, float step)
{
	float value, temps;

	if (type == 'c' || type == 'C')
	{
		printf("%3s     %10s\n", "\nFahrenheit", "Celsius");

		for (value = lower; value <= upper; value += step)
		{
			/* convert to degree celsius */
			temps = (5.0 / 9.0) * (value - 32);
			printf("%3.2f     %10.2f\n", value, temps);
		}
	}
	else if (type == 'f' || type == 'F')
	{
		printf("%3s     %10s\n", "\nCelsius", "Fahrenheit");
		
		for (value = lower; value <= upper; value += step)
		{
			/* convert to fahrenheit */
			temps = (9 / 5) * (value + 32);
			printf("%3.2f %10.2f\n", value, temps);
		}
	}
}
