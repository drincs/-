#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> map;
vector<int> pre, in;
void lca(int inl, int inr, int preR, int a, int b)
{
    if (inl > inr)
        return;
    int inR = map[pre[preR]], aIn = map[a], bIn = map[b];
    if (aIn < inR && bIn < inR)
    {
        //在左子树
        lca(inl, inR - 1, preR + 1, a, b);
    }
    else if (aIn > inR && bIn > inR)
    {
        //在右子树
        lca(inR + 1, inr, preR + 1 + (inR - inl), a, b);
    }
    else if ((aIn < inR && bIn > inR) || (aIn > inR && bIn < inR))
    {
        printf("LCA of %d and %d is %d.\n", a, b, in[inR]);
    }
    else if (aIn == inR)
    {
        printf("%d is an ancestor of %d.\n", a, b);
    }
    else if (bIn == inR)
    {
        printf("%d is an ancestor of %d.\n", b, a);
    }
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    pre.resize(n + 1);
    in.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in[i]);
        map[in[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &pre[i]);
    }
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (map.count(a) == 0 || map.count(b) == 0)
        {
            if (map.count(a) == 0 && map.count(b) == 0)
            {
                printf("ERROR: %d and %d are not found.\n", a, b);
            }
            else
            {
                printf("ERROR: %d is not found.\n", map.count(a) == 0 ? a : b);
            }
        }
        else
        {
            lca(1, n, 1, a, b);
        }
    }
    system("pause");
    return 0;
}