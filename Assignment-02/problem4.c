#include <stdio.h>
#define MAX 1000

int main() {
    int n, a[MAX], r[MAX], K, T;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d %d", &K, &T);

    long total = 0;
    for (int i = 0; i < n; i++) total += a[i];
    printf("Total Distance: %ld\n", total);

    /* Kadane's algorithm with start/end tracking */
    long cur = a[0], best = a[0];
    int s = 0, bs = 0, be = 0;
    for (int i = 1; i < n; i++) {
        if (cur < 0) { cur = a[i]; s = i; }
        else cur += a[i];
        if (cur > best) { best = cur; bs = s; be = i; }
    }
    printf("Maximum Contiguous Distance: %ld\n", best);
    printf("Starting Position: %d\n", bs + 1);
    printf("Ending Position: %d\n", be + 1);

    /* shortest window with sum >= T (sliding window; values non-negative) */
    int left = 0, minLen = n + 1;
    long sum = 0;
    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum >= T && left <= right) {
            if (right - left + 1 < minLen) minLen = right - left + 1;
            sum -= a[left++];
        }
    }
    if (minLen == n + 1) printf("Minimum Locations Required: Not possible\n");
    else printf("Minimum Locations Required: %d\n", minLen);

    /* rotate right by K */
    K %= n;
    for (int i = 0; i < n; i++) r[(i + K) % n] = a[i];
    printf("Rotated Array:");
    for (int i = 0; i < n; i++) printf(" %d", r[i]);
    printf("\n");

    /* inversion count */
    int inv = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) inv++;
    printf("Inversion Count: %d\n", inv);
    return 0;
}
