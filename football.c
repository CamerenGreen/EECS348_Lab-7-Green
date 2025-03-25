#include <stdio.h>
#include "football.h"

int findCombinations(int score) {
    int count = 0;
    
    if (score <= 1) return 0;
    
    for (int td8 = 0; td8 * 8 <= score; td8++) {
        for (int td7 = 0; td7 * 7 <= score; td7++) {
            for (int td6 = 0; td6 * 6 <= score; td6++) {
                for (int fg = 0; fg * 3 <= score; fg++) {
                    int safety = (score - (td8*8 + td7*7 + td6*6 + fg*3)) / 2;
                    if (safety >= 0 && (td8*8 + td7*7 + td6*6 + fg*3 + safety*2) == score) {
                        printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d Safety\n",
                              td8, td7, td6, fg, safety);
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
