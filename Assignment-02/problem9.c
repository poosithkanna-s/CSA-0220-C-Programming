#include <stdio.h>
#define MAX 50

int a[MAX][MAX][MAX];

int main() {
    int L, R, C;
    scanf("%d %d %d", &L, &R, &C);
    for (int f = 0; f < L; f++)
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) scanf("%d", &a[f][r][c]);

    long total = 0, floorSum[MAX] = {0};
    int occupied = 0, unoccupied = 0;
    int fmax[MAX], fmin[MAX], even[MAX] = {0}, odd[MAX] = {0};

    for (int f = 0; f < L; f++) {
        fmax[f] = fmin[f] = a[f][0][0];
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                int v = a[f][r][c];
                total += v;
                floorSum[f] += v;
                if (v > 0) occupied++; else unoccupied++;
                if (v > fmax[f]) fmax[f] = v;
                if (v < fmin[f]) fmin[f] = v;
                if (v % 2 == 0) even[f]++; else odd[f]++;   /* 0 counts as even */
            }
    }

    printf("Total Patients: %ld\n", total);
    printf("Occupied Beds: %d\n", occupied);
    printf("Unoccupied Beds: %d\n", unoccupied);

    printf("Floor-wise Patient Counts:\n");
    int best = 0;
    for (int f = 0; f < L; f++) {
        printf("Floor %d: %ld\n", f + 1, floorSum[f]);
        if (floorSum[f] > floorSum[best]) best = f;
    }
    printf("Floor With Maximum Patients: %d\n", best + 1);

    printf("Floor-wise Maximum and Minimum:\n");
    for (int f = 0; f < L; f++)
        printf("Floor %d: Maximum = %d, Minimum = %d\n", f + 1, fmax[f], fmin[f]);

    printf("Even and Odd Counts:\n");
    for (int f = 0; f < L; f++)
        printf("Floor %d: Even = %d, Odd = %d\n", f + 1, even[f], odd[f]);

    printf("Array After Reversing Floors:\n");
    for (int f = 0; f < L; f++) {
        printf("Floor %d:\n", f + 1);
        int src = L - 1 - f;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) printf("%d ", a[src][r][c]);
            printf("\n");
        }
    }
    return 0;
}
