#include <stdio.h>

int year(int x,int y);

int main()
{
    int x,y;
    scanf("%d,%d",&x,&y);
    
    int total = year(x,y);
    printf("%d\n",total);
    for(int i = x;i <= y;i++)
    {
        if(i % 4 == 0)
        {
            if(i % 100 == 0 && i % 400 != 0)
            {
                continue;
            }
            else
            {
                printf("%d ",i);
                continue;
            }
        }
        else
        {
            continue;
        }
    }
    return 0;
}
int year(int x,int y)
{
    int total = 0;

    for(int i = x;i <= y;i++)
    {
        if(i % 4 == 0)
        {
            if(i % 100 == 0 && i % 400 != 0)
            {
                continue;
            }
            else
            {
                total++;
                continue;
            }
        }
        else
        {
            continue;
        }
    }
    return total;
}