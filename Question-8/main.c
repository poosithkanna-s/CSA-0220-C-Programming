#include <stdio.h>

int main() {
    int exp, score;
    scanf("%d %d", &exp, &score);

    if (exp < 3)
        printf("Level: Junior");
    else if (exp <= 7) {
        if (score >= 80)
            printf("Level: Mid-Level");
        else
            printf("Level: Junior");
    }
    else {
        if (score >= 85)
            printf("Level: Senior");
        else if (score >= 80)
            printf("Level: Mid-Level");
        else
            printf("Level: Junior");
    }

    return 0;
}