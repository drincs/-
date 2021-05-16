#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int &a, int &b)
{
    return a > b;
}
int main()
{
    int nc, np;
    int c[100001], p[100001];
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++)
    {
        scanf("%d", &c[i]);
    }
    sort(c, c + nc, cmp);
    scanf("%d", &np);
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &p[i]);
    }
    sort(p, p + np, cmp);
    int res = 0;
    for (int i = 0; i < nc && i < np && c[i] > 0 && p[i] > 0; i++)
    {
        res += c[i] * p[i];
    }
    for (int i = nc - 1, j = np - 1; i >= 0 && j >= 0 && c[i] < 0 && p[j] < 0; i--, j--)
    {
        res += c[i] * p[j];
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}