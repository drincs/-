#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 1001;
int dp[MAXN][MAXN];
string S;
int main()
{
    getline(cin, S);
    int len = S.length();
    int ans = 1;
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len - 1)
        {
            dp[i][i + 1] = S[i] == S[i + 1] ? 1 : 0;
            if (dp[i][i + 1] == 1)
            {
                ans = 2;
            }
        }
    }
    for (int L = 3; L <= len; L++)
    {
        for (int i = 0; i + L - 1 < len; i++)
        {
            int j = i + L - 1;
            if (dp[i + 1][j - 1] == 1 && S[i] == S[j])
            {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }

    printf("%d\n", ans);
    system("pause");
    return 0;
}