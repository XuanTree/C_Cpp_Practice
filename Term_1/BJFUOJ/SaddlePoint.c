#include <stdio.h>//AI Assisted
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int Square[200][200];
    int saddle_points[200][2]; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &Square[i][j]);
        }
    }
    int count = 0; 
    for (int i = 0; i < n; i++) {
        int row_min = Square[i][0];
        int min_col = 0;
        for (int j = 1; j < m; j++) {
            if (Square[i][j] < row_min) {
                row_min = Square[i][j];
                min_col = j;
            }
        }
        int is_saddle = 1;
        for (int k = 0; k < n; k++) {
            if (Square[k][min_col] > row_min) {
                is_saddle = 0;
                break;
            }
        }
        if (is_saddle) {
            saddle_points[count][0] = i;      
            saddle_points[count][1] = min_col; 
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", saddle_points[i][0], saddle_points[i][1]);
    }
    return 0;
}