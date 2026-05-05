#include <stdio.h>
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        
        long long gcd_val = gcd(a, b);
        long long lcm_val = lcm(a, b);
        
        printf("%lld %lld\n", gcd_val, lcm_val);
    }
    return 0;
}