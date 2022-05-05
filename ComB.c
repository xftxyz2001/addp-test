#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 【算法3.2 用动态规划求解组合问题】
/*功能：求解。
输入：正整数n,m
输出：输出的结果
*/
int ComB(int n, int m)
{
    // int C[n + 1][m + 1], i, j; /*为更加简洁，本例数组下标从1开始*/
    int i, j;
    int **C = (int **)malloc(sizeof(int *) * (n + 1));
    for (i = 0; i <= n; i++)
    {
        C[i] = (int *)malloc(sizeof(int) * (m + 1));
    }
    for (j = 1; j <= m; j++)
        C[1][j] = 0;
    for (i = 1; i <= n; i++)
        C[i][1] = i;
    for (i = 2; i <= n; i++)
        for (j = 2; j <= m; j++)
            if (i < j)
                C[i][j] = 0;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    return (C[n][m]);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n, m;
    n = rand() % 10 + 1;
    m = rand() % n;
    printf("C_{%d}^{%d}=%d\n", n, m, ComB(n, m));
    return 0;
}
