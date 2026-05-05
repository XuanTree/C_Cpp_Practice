#include <stdio.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int maxSum = 0;
    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int currentSum = matrix[i][j] + matrix[i][j+1] + matrix[i+1][j] + matrix[i+1][j+1];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxRow = i;
                maxCol = j;
            }
        }
    }
    printf("%d %d %d\n", maxSum, maxRow, maxCol);
    return 0;
}