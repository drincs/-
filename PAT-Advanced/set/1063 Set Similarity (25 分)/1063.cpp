#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n, m, k;
    set<int> all[51];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &temp);
            all[i].insert(temp);
        }
    }
    scanf("%d", &k);
    int a, b;
    while (k--)
    {
        scanf("%d%d", &a, &b);
        int nc = 0, nt = all[b].size();
        //计算nc
        set<int>::iterator it = all[a].begin();
        while (it != all[a].end())
        {
            if (all[b].find(*it) != all[b].end())
            {
                nc++;
            }
            else
                nt++;
            it++;
        }
        printf("%.1f%\n", nc * 1.0 / nt * 100);
    }
    system("pause");
    return 0;
}