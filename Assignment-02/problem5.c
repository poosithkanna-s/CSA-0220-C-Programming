#include <stdio.h>
#define MAX 100

int main() {
    int n, m, a[MAX][MAX];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);

    int rowTotal[MAX] = {0}, colTotal[MAX] = {0};
    int passedAll = 0;
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int j = 0; j < m; j++) {
            rowTotal[i] += a[i][j];
            colTotal[j] += a[i][j];
            if (a[i][j] < 50) ok = 0;
        }
        if (ok) passedAll++;
    }

    printf("Student Totals:\n");
    for (int i = 0; i < n; i++) printf("%d ", rowTotal[i]);
    printf("\n");

    printf("Subject Averages:\n");
    for (int j = 0; j < m; j++) printf("%.2f ", (double)colTotal[j] / n);
    printf("\n");

    int topper = 0, low = 0;
    for (int i = 1; i < n; i++)
        if (rowTotal[i] > rowTotal[topper]) topper = i;
    for (int j = 1; j < m; j++)
        if (colTotal[j] < colTotal[low]) low = j;   /* compare sums: avoids float issues */

    printf("Topper Position: %d\n", topper + 1);
    printf("Lowest Average Subject: %d\n", low + 1);
    printf("Students Passed All Subjects: %d\n", passedAll);

    printf("Transpose:\n");
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
