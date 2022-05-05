#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define MAXW 100

//问题表示
int n = 5, W = 10;                // 5种物品, 限制重量不超过10
int w[MAXN] = {0, 2, 2, 6, 5, 4}; //下标0不用
int v[MAXN] = {0, 6, 3, 5, 4, 6}; //下标0不用
//求解结果表示
int dp[MAXN][MAXW];
int x[MAXN];
int maxv;

void Knap() //动态规划法求0/1背包问题
{
    int i, r;
    for (i = 0; i <= n; i++) //置边界条件dp[i][0]=0
        dp[i][0] = 0;
    for (r = 0; r <= W; r++) //置边界条件dp[0][r]=0
        dp[0][r] = 0;
    for (i = 1; i <= n; i++)
    {
        for (r = 1; r <= W; r++)
            if (r < w[i])
                dp[i][r] = dp[i - 1][r];
            else
                // dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);
                dp[i][r] = (((dp[i - 1][r]) > (dp[i - 1][r - w[i]] + v[i])) ? (dp[i - 1][r]) : (dp[i - 1][r - w[i]] + v[i]));
    }
}

void Buildx() //回推求最优解
{
    int i = n, r = W;
    maxv = 0;
    while (i >= 0) //判断每个物品
    {
        if (dp[i][r] != dp[i - 1][r])
        {
            x[i] = 1;     //选取物品i
            maxv += v[i]; //累计总价值
            r = r - w[i];
        }
        else
            x[i] = 0; //不选取物品i
        i--;
    }
}

int main(int argc, char const *argv[])
{
    Knap();
    Buildx();
    return 0;
}
