#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//问题表示
int a[] = {2, 1, 5, 3, 6, 4, 8, 9, 7};
int n = sizeof(a) / sizeof(a[0]);

//求解结果表示
int ans = 0;
int dp[MAX];
void solve(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                // dp[i] = max(dp[i], dp[j] + 1);
                dp[i] = (((dp[i]) > (dp[j] + 1)) ? (dp[i]) : (dp[j] + 1));
        }
    }
    ans = dp[0];
    for (i = 1; i < n; i++)
        // ans = max(ans, dp[i]);
        ans = (((ans) > (dp[i])) ? (ans) : (dp[i]));
}

void showSeq(int a[], int n, char *s)
{
    printf("%s:\t", s);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// void displayAns(int dp[], int n)
// {
//     int i, j, k;
//     for (j = 0; j < n; j++) //求dp中最大元素dp[maxj]
//         if (dp[j] > dp[ans])
//             ans = j;
//     for (i = ans, k = 0; i >= 0; i--)
//     {
//         if (dp[i] == dp[ans])
//             a[k++] = a[i];
//     }
//     showSeq(a, k, "MaxAscSubSeq");
// }

int main(int argc, char const *argv[])
{
    showSeq(a, n, "a");
    solve(a, n);
    printf("ans = %d\n", ans);
    showSeq(dp, n, "dp");
    // displayAns(dp, n);
    return 0;
}
