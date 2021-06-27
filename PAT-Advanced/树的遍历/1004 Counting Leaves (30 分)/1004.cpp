#include <iostream>
#include <vector>
using namespace std;
vector<int> nodes[101];
int hashTable[101] = {0};
int maxLevel = 0;
void dfs(int root, int level)
{
    if (level > maxLevel)
    {
        maxLevel = level;
    }
    if (nodes[root].size() == 0)
    {
        hashTable[level]++;
    }
    for (int i = 0; i < nodes[root].size(); i++)
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
    for (int i = 1; i <= maxLevel; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", hashTable[i]);
    }
    if (maxLevel > 0)
        printf("\n");
    system("pause");
    return 0;
}