#include <stdio.h>
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF){
        int moveArray[n];
        int j = 1;
        for(int i = m;i < n;i++){
            moveArray[i] = j;
            j++;
        }
        for(int i = 0;i < m;i++){
            moveArray[i] = j;
            j++;
        }
        for(int i = 0;i < n;i++)
        {
            printf("%d ",moveArray[i]);
        }
    }
    return 0;
}