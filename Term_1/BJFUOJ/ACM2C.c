#include <stdio.h>
#define N 100000
int isPrime(int num){
    if(num < 2){
        return 0;
    }
    if(num == 2){
        return 1;
    }
    for(int i = 2;i < num/2;i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}
void isGood(int num){
    int is_good = 0;
    for(int i = 4;i < N;i++){
        int j = num - i;
        if(!isPrime(j)){
            is_good = 1;
            break;
        }
    }
    if(is_good){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
int main(){
    //输入数字n.表示一共有几组输入
    int n;
    scanf("%d",&n);
    //每一组数字具体是多少
    int arr[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i < n;i++){
        isGood(arr[i]);
    }
    return 0;
}