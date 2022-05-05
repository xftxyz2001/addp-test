#include <stdio.h>
#include <stdlib.h>

#define MAX 51 //序列中最多的字符个数
//问题表示
// char x[] = {a，b，c，b，d，b}
char x[] = {'a', 'b', 'c', 'b', 'd', 'b'};
// a，c，b，b，a，b，d，b，b
char y[] = {'a', 'c', 'b', 'b', 'a', 'b', 'd', 'b', 'b'};

int m = 6, n = 9;
int dp[MAX][MAX]; //动态规划数组
// string a, b;       //求解结果表示
char subs[MAX];
int subs_len = 0; //

void LCSlength() //求dp
{
    int i, j;
    for (i = 0; i <= m; i++) //将dp[i][0]置为0, 边界条件
        dp[i][0] = 0;
    for (j = 0; j <= n; j++) //将dp[0][j]置为0, 边界条件
        dp[0][j] = 0;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++) //两重for循环处理x、y的所有字符
        {
            if (x[i - 1] == y[j - 1]) //情况(1)
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else //情况(2)
                // dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                dp[i][j] = (((dp[i][j - 1]) > (dp[i - 1][j])) ? (dp[i][j - 1]) : (dp[i - 1][j]));
        }
}

void Buildsubs() //由dp构造从subs
{
    int k = dp[m][n]; // k为a和b的最长公共子序列长度
    int i = m;
    int j = n;
    while (k > 0) //在subs中放入最长公共子序列(反向)
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else //与上方、左边元素值均不相等
        {
            // subs.push_back(x[i - 1]); // subs中添加a[i-1]
            subs[subs_len++] = x[i - 1];
            i--;
            j--;
            k--;
        }
}

int main(int argc, char const *argv[])
{
    // print x
    int i;
    for (i = 0; i < m; i++)
        printf("%c", x[i]);
    printf("\n");
    // print y
    for (i = 0; i < n; i++)
        printf("%c", y[i]);
    printf("\n");
    
    LCSlength();
    Buildsubs();
    for (int i = 0; i < subs_len; i++)
        printf("%c", subs[i]);
    return 0;
}
