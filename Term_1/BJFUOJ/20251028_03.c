#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
int* removeElement(int *array,int index){
    for(int i = index;i < 9;i++){
        array[i] = array[i + 1];
    }
    return array;
}
int* bubbleSort(int *array){
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9 - i;j++){
            if(array[j] >= array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}
int main(){
    int array[N] = {0};
    srand(time(NULL));
    for(int i = 0;i < 10;i++){
        array[i] = rand() % 100 + 1;
    }
    for(int i = 0;i < 10;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    int element;
    printf("Please input the element you want to remove:\n");
    scanf("%d",&element);
    int index;
    int isExist = 0;
    for(int i = 0;i < 10;i++){
        if(element == array[i]){
            index = i;
            isExist = 1;
        }
    }
    if(isExist){
        removeElement(array,index);
        printf("Successfully removed!\n");
        bubbleSort(array);
        for(int j = 0;j < 9;j++){
            printf("%d ",array[j]);
        }
    }
    else{
        printf("Please reinput a number:\n");
    }
    return 0;
}