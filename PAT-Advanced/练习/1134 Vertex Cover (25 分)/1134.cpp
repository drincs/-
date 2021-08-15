#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> tmp;
    vector<vector<int>> v(n, tmp);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int nv;
        vector<int> hash_edge(m, 0);
        scanf("%d", &nv);
        for (int j = 0; j < nv; j++)
        {
            int vi;
            scanf("%d", &vi);
            for (int t = 0; t < v[vi].size(); t++)
            {
                hash_edge[v[vi][t]] = 1;
            }
        }
        bool yes = true;
        for (int j = 0; j < m; j++)
        {
            if (hash_edge[j] == 0)
            {
                yes = false;
                break;
            }
        }
        if (yes)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    system("pause");
    return 0;
}