#include <stdio.h>
#define MAX 1000

int main() {
    int n, a[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    long total = 0;
    int max = a[0], min = a[0];
    for (int i = 0; i < n; i++) {
        total += a[i];
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    double avg = (double)total / n;

    int above = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > avg) above++;

    printf("Total Consumption: %ld\n", total);
    printf("Average Consumption: %.2f\n", avg);
    printf("Maximum Consumption: %d\n", max);
    printf("Minimum Consumption: %d\n", min);
    printf("Days Above Average: %d\n", above);

    printf("Maximum Consumption Position:");
    for (int i = 0; i < n; i++)
        if (a[i] == max) printf(" %d", i + 1);   /* 1-based positions */
    printf("\n");

    printf("Reversed Array:");
    for (int i = n - 1; i >= 0; i--) printf(" %d", a[i]);
    printf("\n");
    return 0;
}
