#include <stdio.h>
int isPrime(int num)
{
    if (num == 1)
    {
        return 0;
    }
    for (int i = 2; i <= num - 1; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int x;
    while (scanf("%d", &x) != EOF)
    {
        int array[x];
        for (int i = 0; i < x; i++)
        {
            scanf("%d", &array[i]);
        }
        for (int j = 0; j < x; j++)
        {
            if (isPrime(array[j]))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}