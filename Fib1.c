#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int dp[MAX];   //所有元素初始化为0
int count = 1; //累计调用的步骤

int Fib1(int n) //算法1
{
    dp[1] = dp[2] = 1;
    printf("(%d)计算出Fib(1)=1\n", count++);
    printf("(%d)计算出Fib(2)=1\n", count++);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        printf("(%d)计算出Fib(%d)=%d\n", count++, i, dp[i]);
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n = rand() % 10 + 1;
    int fb = Fib1(n);
    printf("Fib(%d)=%d\n", n, fb);
    return 0;
}
