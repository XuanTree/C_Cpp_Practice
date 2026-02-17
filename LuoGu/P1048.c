#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
int main() {
    int T, M;
    scanf("%d %d", &T, &M);
    int time[105], value[105];
    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &time[i], &value[i]);
    }
    int dp[1005] = {0};
    for (int i = 1; i <= M; i++) {
        for (int j = T; j >= time[i]; j--) {
            dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
        }
    }
    printf("%d\n", dp[T]);
    return 0;
}