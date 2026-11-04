#include <stdio.h>
#define MAX 100

int main() {
    int n, m, a[MAX][MAX];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);

    long rowSum[MAX] = {0}, colSum[MAX] = {0}, all = 0;
    int dmax[MAX], dmin[MAX];
    for (int j = 0; j < m; j++) { dmax[j] = a[0][j]; dmin[j] = a[0][j]; }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            rowSum[i] += a[i][j];
            colSum[j] += a[i][j];
            all += a[i][j];
            if (a[i][j] > dmax[j]) dmax[j] = a[i][j];
            if (a[i][j] < dmin[j]) dmin[j] = a[i][j];
        }

    printf("City Averages:\n");
    for (int i = 0; i < n; i++) printf("%.2f ", (double)rowSum[i] / m);
    printf("\nDaily Maximum:\n");
    for (int j = 0; j < m; j++) printf("%d ", dmax[j]);
    printf("\nDaily Minimum:\n");
    for (int j = 0; j < m; j++) printf("%d ", dmin[j]);
    printf("\n");

    int bestCity = 0, bestDay = 0;
    for (int i = 1; i < n; i++) if (rowSum[i] > rowSum[bestCity]) bestCity = i;
    for (int j = 1; j < m; j++) if (colSum[j] > colSum[bestDay]) bestDay = j;
    printf("Highest Average City: %d\n", bestCity + 1);
    printf("Highest Average Day: %d\n", bestDay + 1);

    double overall = (double)all / (n * m);
    int above = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] > overall) above++;
    printf("Temperatures Above Overall Average: %d\n", above);

    printf("Continuously Increasing Cities:");
    int found = 0;
    for (int i = 0; i < n; i++) {
        int inc = 1;
        for (int j = 1; j < m; j++)
            if (a[i][j] <= a[i][j - 1]) { inc = 0; break; }
        if (inc) { printf(" %d", i + 1); found = 1; }
    }
    if (!found) printf(" None");
    printf("\n");

    /* clockwise spiral */
    printf("Spiral Order:\n");
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) printf("%d ", a[top][j]);
        top++;
        for (int i = top; i <= bottom; i++) printf("%d ", a[i][right]);
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) printf("%d ", a[bottom][j]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) printf("%d ", a[i][left]);
            left++;
        }
    }
    printf("\n");
    return 0;
}
