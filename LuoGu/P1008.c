#include <stdio.h>
int isValidCombination(int a, int b, int c) {
    if (a < 100 || a > 999 || b < 100 || b > 999 || c < 100 || c > 999)
        return 0;
    if (b != 2 * a || c != 3 * a)
        return 0;
    int digits[10] = {0}; 
    
    digits[a / 100] = 1;
    digits[(a / 10) % 10] = 1;
    digits[a % 10] = 1;
    
    
    digits[b / 100] = 1;
    digits[(b / 10) % 10] = 1;
    digits[b % 10] = 1;
    digits[c / 100] = 1;
    digits[(c / 10) % 10] = 1;
    digits[c % 10] = 1;
    for (int i = 1; i <= 9; i++) {
        if (digits[i] != 1)
            return 0;
    }
    return 1;
}
int main() {
    for (int i = 123; i <= 329; i++) {
        int num1 = i;
        int num2 = i * 2;
        int num3 = i * 3;
        if (isValidCombination(num1, num2, num3)) {
            printf("%d %d %d\n", num1, num2, num3);
        }
    }
    return 0;
}