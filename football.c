#include "football.h"
#include <stdio.h>

void findCombinations(int score) {
    printf("\nPossible combinations of scoring plays for %d:\n\n", score);
    for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {
        for (int tdfg = 0; tdfg * 7 <= score; tdfg++) {
            for (int td = 0; td * 6 <= score; td++) {
                for (int fg = 0; fg * 3 <= score; fg++) {
                    int safety = score - (td2pt * 8 + tdfg * 7 + td * 6 + fg * 3);
                    if (safety >= 0 && safety % 2 == 0) {
                        safety /= 2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", 
                               td2pt, tdfg, td, fg, safety);
                    }
                }
            }
        }
    }
    printf("\n");
}
