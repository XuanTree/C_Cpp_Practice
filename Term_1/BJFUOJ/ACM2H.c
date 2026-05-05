#include <stdio.h>
int judgeWater(int *array, int size) {
    if (size < 3) {
        return 0;
    }
    int left = 0, right = size - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    while (left < right) {
        if (array[left] < array[right]) {
            if (array[left] >= leftMax) {
                leftMax = array[left];
            } else {
                water += leftMax - array[left];
            }
            left++;
        } else {
            if (array[right] >= rightMax) {
                rightMax = array[right];
            } else {
                water += rightMax - array[right];
            }
            right--;
        }
    }
    return water;
}
int main() {
    int T, len;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &len);
        int holes[len];
        for (int i = 0; i < len; i++) {
            scanf("%d", &holes[i]);
        }
        printf("%d\n", judgeWater(holes, len));
    }
    return 0;
}
//AI Assisted.I GAVE UP.
// #include <stdio.h>
// int findMin(int *array,int size,int start){
//     int min = array[0];
//     for(int i = start;i < size;i++){
//         if(array[i] < min){
//             min = array[i];
//         }
//     }
//     return min;
// }
// int judgeWater(int *array,int size){
//     if(size < 3){
//         return 0;
//     }
//     else{
//         int min = findMin(array,size,0);
//         int volume = 0;
//         int steps = 1;
//         int* p1;
//         for(int i = 0;i < size;i++){
//             if(array[i] > min){
//                 p1 = &array[i];
//                 break;
//             }
//         }
//         int* p2 = p1;
//         while(p2 < &array[size-1]){
//             p2++;
//             if(*p2 == *(p2+1)){
//                 steps++;
//             }
//             else{
//                 p2 = p2 + 1;
//                 int smaller = (*p1 < *p2) ? *p1 : *p2;
//                 volume += (smaller - min) * steps;
//                 min = findMin(array,size,p2 - array);
//                 steps = 1;
//                 p1 = p2;
//             }
//         }
//         return volume;
//     }
// }
// int main(){
//     int T,len;
//     scanf("%d",&T);
//     while(T--){
//         scanf("%d",&len);
//         int holes[len]; 
//         for(int i = 0;i < len;i++){
//             scanf("%d",&holes[i]);
//         }
//         printf("%d\n",judgeWater(holes,len));
//     }
//     return 0;
// }