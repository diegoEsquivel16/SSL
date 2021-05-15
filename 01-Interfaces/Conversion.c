#include "Conversion.h"

double Celsius(double fahrenheit) 
{
	return (5.0 / 9.0)*(fahrenheit - 32.0);
}

double Fahrenheit(double celsius)
{	
	return (celsius * (9.0 / 5.0)) + 32.0;
}