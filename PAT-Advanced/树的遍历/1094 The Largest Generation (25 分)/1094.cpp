#include <iostream>
#include <vector>
using namespace std;
vector<int> nodes[100];
int hashtable[101] = {0};
void dfs(int root, int level)
{
    hashtable[level]++;
    int size = nodes[root].size();
    for (int i = 0; i < size; i++)
    {
        dfs(nodes[root][i], level + 1);
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int id, k;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            int cid;
            scanf("%d", &cid);
            nodes[id].push_back(cid);
        }
    }
    dfs(01, 1);
    int maxnum = 0, level = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (hashtable[i] > maxnum)
        {
            maxnum = hashtable[i];
            level = i;
        }
    }
    printf("%d %d\n", maxnum, level);
    system("pause");
    return 0;
}