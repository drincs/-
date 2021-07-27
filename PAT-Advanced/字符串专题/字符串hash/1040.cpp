#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAXN = 1001;
const ll P = 10000019;
const ll mod = 1000000007;
ll powP[MAXN], H1[MAXN], H2[MAXN];
void init()
{
    powP[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        powP[i] = (powP[i - 1] * P) % mod;
    }
}
void calH(ll h[], string &str)
{
    h[0] = str[0];
    for (int i = 1; i < str.length(); i++)
    {
        h[i] = (h[i - 1] * P + str[i]) % mod;
    }
}
int calSubH(ll h[], int i, int j)
{
    if (i == 0)
        return h[j];
    return ((h[j] - h[i - 1] * powP[j - i + 1]) % mod + mod) % mod;
}
int binarySearch(int l, int r, int len, int i, int isEven)
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        int h1l = i - mid + isEven, h1r = i;
        int h2l = len - 1 - (i + mid), h2r = len - 1 - (i + isEven);
        int hashL = calSubH(H1, h1l, h1r);
        int hashR = calSubH(H2, h2l, h2r);
        if (hashL != hashR)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l - 1;
}
int main()
{
    init();
    string str;
    getline(cin, str);
    calH(H1, str);
    reverse(str.begin(), str.end());
    calH(H2, str);
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int maxLen = min(i, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 0);
        ans = max(ans, k * 2 + 1);
    }
    for (int i = 0; i < str.length(); i++)
    {
        int maxLen = min(i + 1, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 1);
        ans = max(ans, k * 2);
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}