#include <stdio.h>

int main() {
    int p, r, n;
    scanf("%d %d %d", &p, &r, &n);

    float interest = (float)p * r * n / 100;
    float amount = p + interest;
    float discount = interest * 2 / 100;
    float final_amount = amount - discount;

    printf("%.2f\n", interest);
    printf("%.2f\n", amount);
    printf("%.2f\n", discount);
    printf("%.2f", final_amount);

    return 0;
}