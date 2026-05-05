#include <stdio.h>
#define N 100005
signed main(){
    int num[N];
    int numSum[N];
    numSum[0] = 0;
    int n,m;
    //读取n的值
    scanf("%d",&n);
    //填充num数组
    for(int i = 1;i <= n;i++){
        scanf("%d",&num[i]);
        //获取前n项和数组
        numSum[i] = numSum[i - 1] + num[i];
    }
    //读取m的值
    scanf("%d",&m);
    //计算值
    while(m--){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",numSum[r] - numSum[l - 1]);
    }
    return 0;
}