#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

// 【算法3.3 用动态规划求解合唱队形问题】
//  {/*功能：从n个同学中取出k个，求他们所组成的合唱队形
//  输入：队员人数n和每个学生身高a[i]
//  输出：最长的合唱队形的长度ans*/

int ChorusRank(int n, int a[])
{
    int f1[MAXN];
    int f2[MAXN];
    for (int i = 1; i <= n; i++)
    {
        f1[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i] && f1[i] < f1[j] + 1)
                f1[i] = f1[j] + 1; // 从左到右求最大上升子序列
    }
    for (int i = n; i >= 1; i--)
    {
        f2[i] = 1;
        for (int j = i + 1; j <= n; j++)
            if (a[j] < a[i] && f2[i] < f2[j] + 1)
                f2[i] = f2[j] + 1; //从右到左求最大下降子序列
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (ans < f1[i] + f2[i] - 1)
            ans = f1[i] + f2[i] - 1; //枚举中间最高值
    return ans;                      //返回最长合唱队形的长度
}

int main(int argc, char const *argv[])
{
    int a[] = {2, 1, 5, 3, 6, 4, 8, 9, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int ans = ChorusRank(n, a);
    printf("ans = %d\n", ans);
    return 0;
}
