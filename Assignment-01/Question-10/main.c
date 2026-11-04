#include <stdio.h>

int main() {
    int units;
    scanf("%d", &units);

    double bill;

    if (units <= 200)
        bill = units * 0.5;
    else if (units <= 400)
        bill = units * 0.65 + 100;
    else if (units <= 600)
        bill = units * 0.80 + 200;
    else
        bill = units * 1.25 + 425;

    if (bill == (long)bill)
        printf("Rs.%ld", (long)bill);
    else
        printf("Rs.%.2f", bill);

    return 0;
}