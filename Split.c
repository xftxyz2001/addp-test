#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 100

int dp[MAXN][MAXN]; //动态规划数组
// 整数拆分问题
void Split(int n, int k) //求解算法
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            if (i == 1 || j == 1)
                dp[i][j] = 1;
            else if (i < j)
                dp[i][j] = dp[i][i];
            else if (i == j)
                dp[i][j] = dp[i][j - 1] + 1;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        }
}
int fun(int n, int k) //求解算法
{
    if (n == 1 || k == 1)
        return 1;
    else if (n < k)
        return fun(n, n);
    else if (n == k)
        return fun(n, n - 1) + 1;
    else
        return fun(n - k, k) + fun(n, k - 1);
}

// 备忘录方法
int dpf(int n, int k) //求解算法
{
    if (dp[n][k] != 0)
        return dp[n][k];
    if (n == 1 || k == 1)
    {
        dp[n][k] = 1;
        return dp[n][k];
    }
    else if (n < k)
    {
        dp[n][k] = dpf(n, n);
        return dp[n][k];
    }
    else if (n == k)
    {
        dp[n][k] = dpf(n, k - 1) + 1;
        return dp[n][k];
    }
    else
    {
        dp[n][k] = dpf(n, k - 1) + dpf(n - k, k);
        return dp[n][k];
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n;
    n = rand() % 10 + 1;
    // Split(n, n);
    // fun(n, n);
    dpf(n, n);
    // printf("C_{%d}^{%d}=%d\n", n, k, dp[n][k]);
    return 0;
}
