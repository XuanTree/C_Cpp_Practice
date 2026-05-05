#include <stdio.h>
int SelectBackage(int a,int b,int c){//应该是Package,但不知道题目为啥写成了Backage.
    int array[3] = {a,b,c};
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 2 - i;j++){
            if(array[j + 1] < array[j]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array[1];
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d",SelectBackage(a,b,c));
    return 0;
}