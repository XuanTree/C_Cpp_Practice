#include <stdio.h>
int main(){
    int z;
    int count = 0;
    while(scanf("%d",&z) != EOF){
        if(z >= 700){
            printf("\nPlease reinput a number(z < 700):");
        }
        else{
            for(int i = 0;i < 100;i++){
                for(int j = 0;j < 100;j++){
                    if(3 * i + 4 * j > z){
                        printf("%d and %d are correct answers!\n",i,j);
                        count++;
                    }
                }
            }
            printf("Total: %d answers.\n",count);
        }
    }
    return 0;
}
