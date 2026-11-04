#include <stdio.h>
#define MAX 1000

int seenBefore(int a[], int i) {
    for (int j = 0; j < i; j++)
        if (a[j] == a[i]) return 1;
    return 0;
}

int main() {
    int n, a[MAX], b[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &a[i]); b[i] = a[i]; }

    /* highest and second highest distinct */
    int first = 0, second = 0, hasFirst = 0, hasSecond = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (!hasFirst) { first = x; hasFirst = 1; }
        else if (x > first) { second = first; hasSecond = 1; first = x; }
        else if (x < first && (!hasSecond || x > second)) { second = x; hasSecond = 1; }
    }
    printf("Highest Marks: %d\n", first);
    if (hasSecond) printf("Second Highest Marks: %d\n", second);
    else printf("Second Highest Marks: Not available\n");

    /* frequency of each distinct mark (order of first appearance) */
    printf("Frequencies:\n");
    for (int i = 0; i < n; i++) {
        if (seenBefore(a, i)) continue;
        int c = 0;
        for (int j = 0; j < n; j++)
            if (a[j] == a[i]) c++;
        printf("%d - %d\n", a[i], c);
    }

    /* passed students */
    int passed = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= 50) passed++;
    printf("Passed Students: %d\n", passed);

    /* longest strictly increasing contiguous run */
    int best = 1, cur = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) cur++;
        else cur = 1;
        if (cur > best) best = cur;
    }
    printf("Longest Increasing Sequence Length: %d\n", best);

    /* smallest absolute difference: sort a COPY, check neighbours */
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (b[j] > b[j + 1]) { int t = b[j]; b[j] = b[j + 1]; b[j + 1] = t; }
    int minDiff = -1, p = 0, q = 0;
    for (int i = 0; i < n - 1; i++) {
        int d = b[i + 1] - b[i];
        if (minDiff == -1 || d < minDiff) { minDiff = d; p = b[i]; q = b[i + 1]; }
    }
    if (n >= 2) printf("Minimum Difference Pair: %d %d\n", p, q);
    else printf("Minimum Difference Pair: Not available\n");

    printf("Reversed Array:");
    for (int i = n - 1; i >= 0; i--) printf(" %d", a[i]);
    printf("\n");
    return 0;
}
