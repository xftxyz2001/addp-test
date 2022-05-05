#include <stdio.h>
#include <stdlib.h>
// int robot(int x, int y);

int solve(int x, int y)
{
    x++;
    y++;
    int **dp = (int **)malloc(sizeof(int *) * x);
    for (int i = 0; i < x; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * y);
    }
    for (int i = 0; i < x; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < y; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < x; i++)
    {
        for (int j = 1; j < y; j++)
        {
            dp[i][j] = 1;
        }
    }
    for (int i = 2; i < x; i++)
    {
        for (int j = 2; j < y; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // 中间部分到每个点都有两条路可走
        }
    }
    return dp[x - 1][y - 1];
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", solve(n, m));
    // printf("%d", robot(n, m));
    return 0;
}

// int robot(int x, int y)
// {
//     if (x == 1 && y == 1)
//     {
//         return 1;
//     }
//     else if (x == 1)
//     {
//         return robot(x, y - 1);
//     }
//     else if (y == 1)
//     {
//         return robot(x - 1, y);
//     }
//     else
//     {
//         return robot(x - 1, y) + robot(x, y - 1);
//     }
// }