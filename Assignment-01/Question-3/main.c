#include <stdio.h>

int main() {
    int total, x, y;
    scanf("%d %d %d", &total, &x, &y);

    int ben = total * x / 100;
    int remaining = total - ben;
    int blackbeard = remaining * y / 100;
    remaining = remaining - blackbeard;
    int each = remaining / 3;

    printf("%d\n%d\n%d\n", ben, blackbeard, each);
    return 0;
}