#include <assert.h>
#include <stdio.h>
#include "Conversion.h"
#include <math.h>
#include <float.h>
#include <stdbool.h>

bool equalDoubles(double expected, double actual)
{
    double integralPart;
    modf(actual, &integralPart);
    return fabs(expected - integralPart) < DBL_EPSILON;
}

int main() {
    
    printf("Going to test Celsius to Fahrenheit convertion:\n");
    printf("-10°C should be 14°F\n");
    assert(equalDoubles(14.0, Fahrenheit(-10.0)));
    printf("0°C should be 32°F\n");
    assert(equalDoubles(32.0, Fahrenheit(0.0)));
    printf("10°C should be 50°F\n");
    assert(equalDoubles(50.0, Fahrenheit(10.0)));

    printf("Going to test Fahrenheit to Celsius convertion:\n");
    printf("-10°F should be -23°C\n");
    assert(equalDoubles(-23.0, Celsius(-10.0)));
    printf("0°F should be -17°C\n");
    assert(equalDoubles(-17.0, Celsius(0.0)));
    printf("10°F should be -12°C\n");
    assert(equalDoubles(-12.0, Celsius(10.0)));
    return 0;
}