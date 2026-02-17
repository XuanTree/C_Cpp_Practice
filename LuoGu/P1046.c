#include <stdio.h>
#define N 20
int main(){
    int array[N];
    for(int i = 0;i < 10;i++){
        scanf("%d",&array[i]);
    }
    int height;
    int count = 0;
    scanf("%d",&height);
    for(int i = 0;i < 10;i++){
        if(height + 30 >= array[i]){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}