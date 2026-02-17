#include <stdio.h>
#include <string.h>
int main() {
    int V, N;
    scanf("%d", &V);
    scanf("%d", &N);
    int volumes[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &volumes[i]);
    }
    int dp[1005] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = V; j >= volumes[i]; j--) {
            if (dp[j] < dp[j - volumes[i]] + volumes[i]) {
                dp[j] = dp[j - volumes[i]] + volumes[i];
            }
        }
    }
    printf("%d\n", V - dp[V]);
    return 0;
}