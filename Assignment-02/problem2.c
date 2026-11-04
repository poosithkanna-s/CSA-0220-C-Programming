#include <stdio.h>
#define MAX 1000

/* 1 if a[i] already occurred before index i */
int seenBefore(int a[], int i) {
    for (int j = 0; j < i; j++)
        if (a[j] == a[i]) return 1;
    return 0;
}

int main() {
    int n, a[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    /* second largest distinct value, without sorting */
    int first = 0, second = 0, hasFirst = 0, hasSecond = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (!hasFirst) { first = x; hasFirst = 1; }
        else if (x > first) { second = first; hasSecond = 1; first = x; }
        else if (x < first && (!hasSecond || x > second)) { second = x; hasSecond = 1; }
    }
    if (hasSecond) printf("Second Largest Distinct Quantity: %d\n", second);
    else printf("Second Largest Distinct Quantity: Not available\n");

    /* zero positions */
    printf("Zero Positions:");
    int zeros = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 0) { printf(" %d", i + 1); zeros++; }
    if (zeros == 0) printf(" None");
    printf("\n");

    /* duplicate occurrences = extra copies of non-zero quantities
       (zeros are reported separately above) */
    int dup = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != 0 && seenBefore(a, i)) dup++;
    printf("Duplicate Occurrences: %d\n", dup);

    /* remove duplicates, keep first occurrence */
    printf("Array After Removing Duplicates:");
    for (int i = 0; i < n; i++)
        if (!seenBefore(a, i)) printf(" %d", a[i]);
    printf("\n");

    /* move zeros to end (matches the sample output: distinct non-zero
       values in original order, then every zero) */
    printf("Array After Moving Zeros:");
    for (int i = 0; i < n; i++)
        if (a[i] != 0 && !seenBefore(a, i)) printf(" %d", a[i]);
    for (int i = 0; i < zeros; i++) printf(" 0");
    printf("\n");
    return 0;
}
