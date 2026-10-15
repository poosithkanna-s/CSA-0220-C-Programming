#include <stdio.h>

int main() {
    long total;
    double x, y;

    printf("Total gold coins: ");
    scanf("%ld", &total);
    printf("Long Ben's share (x%%): ");
    scanf("%lf", &x);
    printf("Blackbeard's share of the remainder (y%%): ");
    scanf("%lf", &y);

    long long_ben = (long)(total * x / 100);
    long remaining = total - long_ben;

    long blackbeard = (long)(remaining * y / 100);
    remaining -= blackbeard;

    long each_pirate = remaining / 3;
    long leftover = remaining % 3;

    printf("Long Ben   : %ld\n", long_ben);
    printf("Blackbeard : %ld\n", blackbeard);
    printf("Each of the other 3 pirates: %ld\n", each_pirate);
    printf("Thrown into the sea: %ld\n", leftover);

    return 0;
}