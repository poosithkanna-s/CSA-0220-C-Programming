#include <stdio.h>
#define MAX 100

int main() {
    int n, m, a[MAX][MAX];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);

    int occupied = 0, rowOcc[MAX] = {0}, colEmpty[MAX] = {0};
    int longest = 0;
    for (int i = 0; i < n; i++) {
        int run = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) { occupied++; rowOcc[i]++; run = 0; }
            else { colEmpty[j]++; run++; if (run > longest) longest = run; }
        }
    }
    int total = n * m, empty = total - occupied;

    int maxRow = 0, maxCol = 0;
    for (int i = 1; i < n; i++)
        if (rowOcc[i] > rowOcc[maxRow]) maxRow = i;
    for (int j = 1; j < m; j++)
        if (colEmpty[j] > colEmpty[maxCol]) maxCol = j;

    printf("Occupied Spaces: %d\n", occupied);
    printf("Empty Spaces: %d\n", empty);
    printf("Maximum Occupied Row: %d\n", maxRow + 1);
    printf("Maximum Empty Column: %d\n", maxCol + 1);

    printf("Completely Occupied Rows:");
    int found = 0;
    for (int i = 0; i < n; i++)
        if (rowOcc[i] == m) { printf(" %d", i + 1); found = 1; }
    if (!found) printf(" None");
    printf("\n");

    printf("Longest Continuous Empty Sequence: %d\n", longest);
    printf("Occupancy Percentage: %.2f\n", occupied * 100.0 / total);
    return 0;
}
