#include <stdio.h>
int main(){
    double total_time = 40;
    double t,v;
    scanf("%lf %lf",&t,&v);
    double timeE = 300 / v;
    double timeW = 100 / v;
    double remaining_timeE = total_time - timeE - t;
    double remaining_timeW = total_time - timeW - t;
    if(remaining_timeE >= 0){
        printf("Malaban");
    }
    else if(remaining_timeE < 0 && remaining_timeW >= 0){
        printf("Xiqu");
    }
    else{
        printf("NOOOOO");
    }
    return 0;
}