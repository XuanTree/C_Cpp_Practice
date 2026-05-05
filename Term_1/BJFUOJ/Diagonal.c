#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int Square[n][n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&Square[i][j]);
        }
    }
    int isGood = 1;
    for(int i = 1;i < n;i++){
        for(int j = 1;j < n;j++){
            if(Square[i][j] == Square[j][i]){
                continue;
            }
            else{
                isGood = 0;
                continue;
            }
        }
    }
    if(isGood){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
