#include <stdio.h>
#include <string.h>
int main() {
    char num[20];
    scanf("%s", num);
    int len = strlen(num);
    int start = 0, end = len - 1;
    if (num[0] == '-') {
        printf("-");
        start = 1;
    }
    while (end >= start && num[end] == '0') {
        end--;
    }
    if (end < start) {
        printf("0\n");
        return 0;
    }
    for (int i = end; i >= start; i--) {
        printf("%c", num[i]);
    }
    printf("\n");
    return 0;
}
//AI Assisted.