#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//问题表示
// string a = "sfdqxbw";
// string b = "gfdgw";
char *a = "sfdqxbw";
char *b = "gfdgw";

//求解结果表示
int dp[MAX][MAX];
void solve() //求dp
{
    int i, j;
    // for (i = 1; i <= a.length(); i++)
    for (i = 1; i <= strlen(a); i++)
        dp[i][0] = i; //把a的i个字符全部删除转换为b
    // for (j = 1; j <= b.length(); j++)
    for (j = 1; j <= strlen(b); j++)
        dp[0][j] = j; //在a中插入b的全部字符转换为b
    // for (i = 1; i <= a.length(); i++)
    for (i = 1; i <= strlen(a); i++)
        // for (j = 1; j <= b.length(); j++)
        for (j = 1; j <= strlen(b); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                // dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                dp[i][j] = ((((((dp[i - 1][j]) < (dp[i][j - 1])) ? (dp[i - 1][j]) : (dp[i][j - 1]))) < (dp[i - 1][j - 1])) ? ((((dp[i - 1][j]) < (dp[i][j - 1])) ? (dp[i - 1][j]) : (dp[i][j - 1]))) : (dp[i - 1][j - 1]));
        }
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
