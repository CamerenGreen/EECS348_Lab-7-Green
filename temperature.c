#include "temperature.h"
#include <stdio.h>


float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Freezing (%.2f°C)\nAdvisory: Bundle up! It's freezing outside.\n", celsius);
    } else if (celsius < 10) {
        printf("Cold (%.2f°C)\nAdvisory: Wear a jacket.\n", celsius);
    } else if (celsius < 25) {
        printf("Comfortable (%.2f°C)\nAdvisory: Enjoy the pleasant weather.\n", celsius);
    } else if (celsius < 35) {
        printf("Hot (%.2f°C)\nAdvisory: Stay hydrated!\n", celsius);
    } else {
        printf("Extreme Heat (%.2f°C)\nAdvisory: Stay indoors if possible.\n", celsius);
    }
}

bool is_valid_kelvin(float kelvin) {
    return kelvin >= 0;
}
