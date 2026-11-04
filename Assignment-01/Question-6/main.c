#include <stdio.h>

int main() {
    int a, b, c, car;
    scanf("%d %d %d %d", &a, &b, &c, &car);

    if (car == a)
        printf("Road A");
    else if (car == b)
        printf("Road B");
    else if (car == c)
        printf("Road C");
    else
        printf("No path exists\n");

    return 0;
}