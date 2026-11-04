#include <stdio.h>
#define MAX 50

int a[MAX][MAX][MAX];

int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int main() {
    int L, R, C;
    scanf("%d %d %d", &L, &R, &C);
    for (int l = 0; l < L; l++)
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) scanf("%d", &a[l][r][c]);

    long total = 0, layerSum[MAX] = {0};
    int primes[MAX] = {0};
    int hi = a[0][0][0], lo = a[0][0][0];
    int hl = 0, hr = 0, hc = 0, ll = 0, lr = 0, lc = 0;

    for (int l = 0; l < L; l++)
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                int v = a[l][r][c];
                total += v;
                layerSum[l] += v;
                if (isPrime(v)) primes[l]++;
                if (v > hi) { hi = v; hl = l; hr = r; hc = c; }
                if (v < lo) { lo = v; ll = l; lr = r; lc = c; }
            }

    printf("Total Vibration Intensity: %ld\n", total);
    printf("Highest Vibration: %d\n", hi);
    printf("Highest Position: (%d,%d,%d)\n", hl + 1, hr + 1, hc + 1);
    printf("Lowest Vibration: %d\n", lo);
    printf("Lowest Position: (%d,%d,%d)\n", ll + 1, lr + 1, lc + 1);

    printf("Layer-wise Intensity:\n");
    int best = 0;
    for (int l = 0; l < L; l++) {
        printf("Layer %d: %ld\n", l + 1, layerSum[l]);
        if (layerSum[l] > layerSum[best]) best = l;
    }
    printf("Layer With Maximum Intensity: %d\n", best + 1);

    printf("Prime Counts:\n");
    for (int l = 0; l < L; l++) printf("Layer %d: %d\n", l + 1, primes[l]);

    if (L == R && R == C) {
        long diag = 0;
        for (int i = 0; i < L; i++) diag += a[i][i][i];
        printf("Main Space Diagonal Sum: %ld\n", diag);
    }

    /* local maxima in the 6 directions */
    int dl[6] = {-1, 1, 0, 0, 0, 0};
    int dr[6] = {0, 0, -1, 1, 0, 0};
    int dc[6] = {0, 0, 0, 0, -1, 1};
    int count = 0;
    /* first pass: count */
    for (int l = 0; l < L; l++)
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                int ok = 1;
                for (int d = 0; d < 6 && ok; d++) {
                    int nl = l + dl[d], nr = r + dr[d], nc = c + dc[d];
                    if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    if (a[nl][nr][nc] >= a[l][r][c]) ok = 0;
                }
                if (ok) count++;
            }
    printf("Local Maximum Sensor Count: %d\n", count);
    /* second pass: print positions */
    for (int l = 0; l < L; l++)
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                int ok = 1;
                for (int d = 0; d < 6 && ok; d++) {
                    int nl = l + dl[d], nr = r + dr[d], nc = c + dc[d];
                    if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    if (a[nl][nr][nc] >= a[l][r][c]) ok = 0;
                }
                if (ok) printf("Local Maximum Position: (%d,%d,%d)\n", l + 1, r + 1, c + 1);
            }
    return 0;
}
