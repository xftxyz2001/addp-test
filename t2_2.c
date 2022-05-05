#include <stdio.h>
#include <stdlib.h>

#define MAXN 200

int dp[MAXN]; // dp[i]表示以a[i]结尾的最长下降序列的长度

int solve(int a[], int n)
{
    //状态转移方程
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] < a[j])
            {
                // dp[i] = max(dp[j] + 1, dp[i]);
                dp[i] = (((dp[j] + 1) > (dp[i])) ? (dp[j] + 1) : (dp[i]));
            }
        }
        // res = max(res, dp[i]);
        res = (((res) > (dp[i])) ? (res) : (dp[i]));
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    int a[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        dp[i] = 1;
    }
    //输出
    printf("%d", solve(a, n));
    return 0;
}
