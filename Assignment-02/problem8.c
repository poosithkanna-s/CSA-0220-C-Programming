#include <stdio.h>
#define MAX 100

int main() {
    int n, m, a[MAX][MAX];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);

    long sum = 0;
    int dark = 0, minV = a[0][0], maxV = a[0][0];
    int minR = 0, minC = 0, maxR = 0, maxC = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
            if (a[i][j] < 50) dark++;
            if (a[i][j] < minV) { minV = a[i][j]; minR = i; minC = j; }
            if (a[i][j] > maxV) { maxV = a[i][j]; maxR = i; maxC = j; }
        }

    printf("Average Intensity: %.2f\n", (double)sum / (n * m));
    printf("Darkest Pixel: %d at (%d,%d)\n", minV, minR + 1, minC + 1);
    printf("Brightest Pixel: %d at (%d,%d)\n", maxV, maxR + 1, maxC + 1);
    printf("Dark Pixel Count: %d\n", dark);

    printf("Negative Image:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%d ", 255 - a[i][j]);
        printf("\n");
    }

    /* rotate 90 degrees clockwise: result has m rows and n columns.
       Row j of the result = column j of the original, read bottom to top. */
    printf("Rotated Image:\n");
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) printf("%d ", a[i][j]);
        printf("\n");
    }

    /* local maxima: compare only with neighbours that exist */
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int v = a[i][j], ok = 1;
            if (i > 0     && a[i - 1][j] >= v) ok = 0;
            if (i < n - 1 && a[i + 1][j] >= v) ok = 0;
            if (j > 0     && a[i][j - 1] >= v) ok = 0;
            if (j < m - 1 && a[i][j + 1] >= v) ok = 0;
            if (ok) count++;
        }
    printf("Local Maximum Count: %d\n", count);
    return 0;
}
