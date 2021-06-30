#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1001;
int father[N];
int hobby[1001] = {0};
int root[1001] = {0};
int findFather(int v)
{
    if (v == father[v])
    {
        return v;
    }
    else
    {
        int F = findFather(father[v]);
        father[v] = F;
        return F;
    }
}
void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
    {
        father[faA] = faB;
    }
}
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}
bool cmp(int &a, int &b)
{
    return a > b;
}
int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int h;
            if (j == 0)
                scanf(": %d", &h);
            else
                scanf("%d", &h);
            if (hobby[h] == 0)
            {
                hobby[h] = i;
            }
            Union(i, findFather(hobby[h]));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        root[findFather(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (root[i] != 0)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    sort(root + 1, root + n + 1, cmp);
    for (int i = 1; i <= ans; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", root[i]);
    }

    system("pause");
    return 0;
}