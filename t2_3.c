#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100

//记录两个水果名字
char arr1[MAXN];
char arr2[MAXN];

int m, n;

// typedef struct
// {
//     int **data;
// } vct2;

// vct2 *init(int m, int n)
// {
//     vct2 *v = (vct2 *)malloc(sizeof(vct2));
//     v = (int **)malloc((m + 1) * sizeof(int *));
//     for (int i = 0; i < m; i++)
//     {
//         v[i] = (int *)malloc((n + 1) * sizeof(int));
//     }
//     return v;
// }

//根据comp数组输出新水果名称
void display(int comp[MAXN][MAXN], int i, int j)
{
    if (i == 0 && j == 0)
    { //输出完成
        return;
    }
    if (i == 0)
    { // arr1输出完成
        display(comp, i, j - 1);
        printf("%c", arr2[j - 1]);
        return;
    }
    else if (j == 0)
    { // arr2输出完成
        display(comp, i - 1, j);
        printf("%c", arr1[i - 1]);
        return;
    }
    if (comp[i][j] == 0)
    { // arr1[i-1] == arr2[j-1]
        display(comp, i - 1, j - 1);
        printf("%c", arr1[i - 1]); //输出当前最后一个字符
        return;
    }
    else if (comp[i][j] == 1)
    {
        display(comp, i - 1, j);
        printf("%c", arr1[i - 1]);
        return;
    }
    else
    {
        display(comp, i, j - 1);
        printf("%c", arr2[j - 1]);
        return;
    }
}

//寻找最长公共子序列子序列
void findFLCS(int dp[MAXN][MAXN], int comp[MAXN][MAXN])
{
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0; //将dp[n][0]设置边界条件
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0; //将dp[0][n]设置为边界条件
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        { //遍历arr1和arr2的所有字符
            if (arr1[i - 1] == arr2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; //比较的字符相同,comp置为0
                comp[i][j] = 0;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j]; //当前方格上方的方格大于左侧的方格，comp置为1
                comp[i][j] = 1;
            }
            else
            {                            // dp[i-1][j] <= dp[i][j-1]
                dp[i][j] = dp[i][j - 1]; //当前方格上方的方格小于等于左侧的方格,comp置为2
                comp[i][j] = 2;
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    printf("输入第一个水果的名称: ");
    scanf("%s", arr1);
    printf("输入第二个水果的名称: ");
    scanf("%s", arr2);

    //计算两个字符串的长度
    m = strlen(arr1);
    n = strlen(arr2);

    //记录arr1和arr2比较的三种情况
    int **comp = (int **)malloc((m + 2) * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        comp[i] = (int *)malloc((n + 2) * sizeof(int));
    }
    //声明动态规划数组
    int **dp = (int **)malloc((m + 2) * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        dp[i] = (int *)malloc((n + 2) * sizeof(int));
    }

    // vector<vector<int>> comp(m + 1, vector<int>(n + 1));
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    findFLCS(dp, comp);
    printf("新水果的名称:");

    display(comp, m, n);
    printf("\n");

    return 0;
}
