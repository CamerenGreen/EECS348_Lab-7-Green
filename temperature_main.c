#include "temperature.h"
#include <stdio.h>

// Declarations from temperature.c
extern float celsius_to_fahrenheit(float c);
extern void categorize_temperature(float c);

int main() {
    float temp;
    printf("Enter temperature in C: ");
    scanf("%f", &temp);
    
    printf("%.2f°C = %.2f°F\n", temp, celsius_to_fahrenheit(temp));
    categorize_temperature(temp);
    return 0;
}
