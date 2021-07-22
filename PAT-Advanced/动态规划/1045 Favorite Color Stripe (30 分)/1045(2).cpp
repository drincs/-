//使用LCS再解一遍
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAXN = 10001;
int A[201];
int dp[201][MAXN], B[MAXN];
int main()
{
    int n, m, l;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &l);
    for (int i = 1; i <= l; i++)
    {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= l; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            int MAX = max(dp[i - 1][j], dp[i][j - 1]);
            if (A[i] == B[j])
            {
                dp[i][j] = MAX + 1;
            }
            else
            {
                dp[i][j] = MAX;
            }
        }
    }
    printf("%d\n", dp[m][l]);
    system("pause");
    return 0;
}