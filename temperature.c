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

int main() {
    float temp;
    int input_scale, target_scale;
    
    printf("Temperature Conversion Utility\n");
    printf("Enter temperature value: ");
    scanf("%f", &temp);
    
    printf("Choose input scale:\n");
    printf("1. Fahrenheit\n2. Celsius\n3. Kelvin\n");
    scanf("%d", &input_scale);
    
    printf("Choose target scale:\n");
    printf("1. Fahrenheit\n2. Celsius\n3. Kelvin\n");
    scanf("%d", &target_scale);
    
    if (input_scale < 1 || input_scale > 3 || target_scale < 1 || target_scale > 3) {
        printf("Invalid scale selection.\n");
        return 1;
    }
    
    if (input_scale == 3 && !is_valid_kelvin(temp)) {
        printf("Error: Kelvin temperature cannot be negative.\n");
        return 1;
    }
    
    float celsius;
    switch (input_scale) {
        case 1: celsius = fahrenheit_to_celsius(temp); break;
        case 2: celsius = temp; break;
        case 3: celsius = kelvin_to_celsius(temp); break;
    }
    
    float result;
    switch (target_scale) {
        case 1: result = celsius_to_fahrenheit(celsius); break;
        case 2: result = celsius; break;
        case 3: result = celsius_to_kelvin(celsius); break;
    }
    
    printf("\nConverted temperature: %.2f ", result);
    switch (target_scale) {
        case 1: printf("°F\n"); break;
        case 2: printf("°C\n"); break;
        case 3: printf("K\n"); break;
    }
    
    categorize_temperature(celsius);
    return 0;
}
