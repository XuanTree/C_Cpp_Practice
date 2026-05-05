#include <stdio.h>
int IsPrime(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    for(int i = 2;i < n;i++){
        if(n % i == 0){
            return 0;
        }
    }
    return n;
}
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int sum = 0;
        for(int i = n;i < 1000;i++){
            if(IsPrime(i)){
                sum += i;
            }
        }
        printf("%d",sum);
    }
    return 0;
}