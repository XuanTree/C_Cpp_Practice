#include <stdio.h>
int gcd(int num1,int num2){
    while(num2 != 0){
        int temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }
    return num1;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",gcd(a,b));
    return 0;
}