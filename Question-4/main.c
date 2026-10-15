#include <stdio.h>

int main() {
    int d1, c1, d2, c2;
    scanf("%d %d %d %d", &d1, &c1, &d2, &c2);

    int dollars = d1 + d2;
    int cents = c1 + c2;

    dollars += cents / 100;
    cents = cents % 100;

    printf("%d\n%d", dollars, cents);

    return 0;
}