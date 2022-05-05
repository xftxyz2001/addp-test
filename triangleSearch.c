#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 100

// 三角形最小路径
//问题表示
int a[MAXN][MAXN];
int n;
//求解结果表示
int ans = 0;
int dp[MAXN][MAXN];  //计从a[0][0]出发到a[i][j]的最短路径
int pre[MAXN][MAXN]; //计走到a[i][j]的直接前驱结点的列号

typedef struct stack
{
    int data[MAXN];
    int len;
} stack;

void push(stack *s, int x)
{
    s->data[s->len] = x;
    s->len++;
}

int pop(stack *s)
{
    s->len--;
    return s->data[s->len];
}

int empty(stack *s)
{
    return s->len == 0;
}

int Search() //求最小和路径ans
{
    int i, j;
    dp[0][0] = a[0][0];
    for (i = 1; i < n; i++) //考虑第1列的边界
    {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        // pre[i][0]=i-1;//记录的是上一行的行号, 列号仍为0
        pre[i][0] = 0; //应该是这个才对
    }
    for (i = 1; i < n; i++) //考虑对角线的边界
    {
        dp[i][i] = a[i][i] + dp[i - 1][i - 1];
        pre[i][i] = i - 1;
    }
    for (i = 2; i < n; i++) //考虑其他有两条达到路径的结点
    {
        for (j = 1; j < i; j++)
        {
            if (dp[i - 1][j - 1] < dp[i - 1][j])
            {
                pre[i][j] = j - 1;
                dp[i][j] = a[i][j] + dp[i - 1][j - 1];
            }
            else
            {
                pre[i][j] = j;
                dp[i][j] = a[i][j] + dp[i - 1][j];
            }
        }
    }
    ans = dp[n - 1][0];
    int k = 0;
    for (j = 1; j < n; j++) //求出最小ans和对应的列号k
    {
        if (ans > dp[n - 1][j])
        {
            ans = dp[n - 1][j];
            k = j;
        }
    }
    return k;
}

void Disppath(int k) //输出最小和路径
{
    int i = n - 1;
    // vector<int> path; //存放逆路径向量path
    stack s;
    s.len = 0;
    while (i >= 0) //从（n-1,k）结点反推求出反向路径
    {
        // path.push_back(a[i][k]);
        push(&s, a[i][k]);
        k = pre[i][k]; //最小路径在前一行中的列号
        i--;           //在前一行查找
    }
    // vector<int>::reverse_iterator it; //定义反向迭代器
    // for (it = path.rbegin(); it != path.rend(); ++it)
    //     printf("%d ", *it); //反向输出构成正向路径
    printf("\nPath: ");
    while (!empty(&s))
    {
        printf("%d ", pop(&s));
    }
    printf("\n");
}

void testinit()
{
    srand(time(NULL));
    n = rand() % 10 + 3;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            a[i][j] = rand() % 10;
        }
    }
}

void displayTriangle()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int k;
    memset(pre, 0, sizeof(pre));
    memset(dp, 0, sizeof(dp));
    // scanf("%d", &n);            //输入三角形的高度
    // for (int i = 0; i < n; i++) //输入三角形
    //     for (int j = 0; j <= i; j++)
    //         scanf("%d", &a[i][j]);
    testinit();
    displayTriangle();
    k = Search();        //求最小路径和
    Disppath(k);         //输出正向路径
    printf("%d\n", ans); //输出最小路径和
    return 0;
}