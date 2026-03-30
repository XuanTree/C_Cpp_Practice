#include <stdio.h>
#include <string.h>
int main(){
    char number[100];
    printf("������һ������(100λ��û��ϵ��):");
    while(scanf("%s",number) != EOF){
        int length = strlen(number);
        printf("����һ��%dλ��",length);
        for (int i = 0;i < length;i++){
            printf("%c ",number[i]);
        }
        printf("\n�������:");
        for(int i = length;i >= 0;i--){
            printf("%c",number[i]);
        }
        printf("\n������һ������(100λ��û��ϵ��):");
    }
    return 0;
}