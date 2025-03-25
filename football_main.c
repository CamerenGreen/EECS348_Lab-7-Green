#include "football.h"
#include <stdio.h>

extern void findCombinations(int score);  // From football.c

int main() {
    int score;
    while (1) {
        printf("Enter score (<=1 to quit): ");
        scanf("%d", &score);
        if (score <= 1) break;
        findCombinations(score);
    }
    return 0;
}
