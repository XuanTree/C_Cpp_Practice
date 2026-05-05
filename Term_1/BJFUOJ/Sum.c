#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = n * (n + 1) / 2;
        printf("%d\n", sum);
    }
    return 0;
}