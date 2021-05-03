#include <stdio.h>
#include "Conversion.h"

const double LOWER = 0; /* lower limit of table */
const double UPPER = 300; /* upper limit */
const double STEP = 20; /* step size */ 

void PrintRows(double(*f)(double));

void PrintRow(double originalTemperature, double convertedTemperature)
{
	printf("%3.0f %3.0f\n", originalTemperature, convertedTemperature);
}

void PrintRows(double(*f)(double))
{
	for (double temperature = LOWER; temperature <= UPPER; temperature += STEP) {
        PrintRow(temperature, (*f)(temperature));
    }
}

void PrintCelsiusTable()
{
	printf("Table: Fahrenheit - Celsius\n");
	PrintRows(Celsius);
}

void PrintFahrenheitTable()
{
	printf("Table: Celsius - Fahrenheit\n");
	PrintRows(Fahrenheit);
}

void PrintTables()
{
	PrintCelsiusTable();
	PrintFahrenheitTable();
}

int main()
{
	PrintTables();
	return 0;
}
