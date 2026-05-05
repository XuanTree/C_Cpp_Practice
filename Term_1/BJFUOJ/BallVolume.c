#include <stdio.h>
#define PI 3.1415927
#include <math.h>

int main()
{
    double r;
    double result;
    while(scanf("%lf",&r) != EOF)
    {
        result = 4 * PI * pow(r,2);
        printf("%.3lf\n",result);
    }
    return 0;
}