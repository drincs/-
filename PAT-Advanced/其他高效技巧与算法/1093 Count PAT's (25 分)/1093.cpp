#include <iostream>
#include <cstring>
const int MAXN = 100001;
const int MOD = 1000000007;
int main()
{
    char s[MAXN];
    scanf("%s", s);
    int len = strlen(s);
    int leftP[MAXN] = {0}, rightT[MAXN] = {0};
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'P')
        {
            if (i == 0)
                leftP[i] = 1;
            else
                leftP[i] = leftP[i - 1] + 1;
        }
        else
        {
            if (i == 0)
                leftP[i] = 0;
            else
                leftP[i] = leftP[i - 1];
        }
    }
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == 'T')
        {
            if (i == len - 1)
                rightT[i] = 1;
            else
                rightT[i] = rightT[i + 1] + 1;
        }
        else
        {
            if (i == len - 1)
                rightT[i] = 0;
            else
                rightT[i] = rightT[i + 1];
            if (s[i] == 'A')
            {
                res = (res + leftP[i] * rightT[i]) % MOD;
            }
        }
    }
    printf("%d\n", res % MOD);
    system("pause");
    return 0;
}