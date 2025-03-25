#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdbool.h>

// Conversion functions
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);

// Categorization function
void categorize_temperature(float celsius);

// Validation function
bool is_valid_kelvin(float kelvin);

// Main program function
void runTemperatureConverter();

#endif
