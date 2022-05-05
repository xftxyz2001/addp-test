#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

// 问题描述
int n = 6;
int a[] = {0, -2, 11, -4, 13, -5, -2}; // a数组不用下标为0的元素

int dp[MAXN];
void maxSubSum() //求dp数组
{
    dp[0] = 0;
    for (int j = 1; j <= n; j++)
        // dp[j] = max(dp[j - 1] + a[j], a[j]);
        dp[j] = (((dp[j - 1] + a[j]) > (a[j])) ? (dp[j - 1] + a[j]) : (a[j]));
}

void displaySrc()
{
    printf("原始数组为: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void displaymaxSumAndSelectedSub() //输出结果
{
    int maxj = 1;
    int i, j, k;
    for (j = 2; j <= n; j++) //求dp中最大元素dp[maxj]
        if (dp[j] > dp[maxj])
            maxj = j;
    for (k = maxj; k >= 1; k--) //找前一个值小于等于0者
        if (dp[k] <= 0)
            break;
    printf("最大连续子序列和: %d\n", dp[maxj]);
    printf("所选子序列: ");
    for (i = k + 1; i <= maxj; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    displaySrc();
    maxSubSum();
    displaymaxSumAndSelectedSub();
    return 0;
}
