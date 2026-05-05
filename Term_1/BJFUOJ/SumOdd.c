#include <stdio.h>
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int sum = 0;
        int array[n - 1];
        for(int i = 0;i <= n - 1;i++){
            scanf("%d",&array[i]);
        }
        for (int i = 0;i <= n - 1;i++){
            if(array[i] % 2 != 0){
                sum += array[i];
            }
        } 
        printf("%d\n",sum);
    }
    return 0;
}