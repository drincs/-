#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10001;
const int MAXM = 101;
int values[MAXN];
int dp[MAXM];
int selected[MAXN];
bool choice[MAXN][MAXM], flag[MAXN];
bool cmp(int &a, int &b)
{
    return a > b;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    values[0] = 0;
    fill(choice[0], choice[0] + MAXN * MAXM, false);
    fill(flag, flag + MAXN, false);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &values[i]);
    }
    //边界
    for (int i = 0; i <= m; i++)
    {
        dp[i] = 0;
    }
    sort(values + 1, values + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int v = m; v >= values[i]; v--)
        {
            if (dp[v] > dp[v - values[i]] + values[i])
            {
                //不选
            }
            else
            {
                dp[v] = dp[v - values[i]] + values[i];
                //当前选中
                choice[i][v] = true;
            }
        }
    }
    if (dp[m] != m)
    {
        printf("No Solution\n");
    }
    else
    {
        int k = n, num = 0, v = m;
        while (k >= 0)
        {
            if (choice[k][v])
            {
                flag[k] = true;
                v -= values[k];
                num++;
            }
            k--;
        }
        for (int i = n; i >= 1; i--)
        {
            if (flag[i] == true)
            {
                printf("%d", values[i]);
                num--;
                if (num > 0)
                    printf(" ");
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}