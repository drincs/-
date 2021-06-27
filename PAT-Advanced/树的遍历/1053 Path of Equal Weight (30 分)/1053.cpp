#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int weight;
    vector<int> child;
} nodes[101];
int n, m, s;
vector<int> temp;
vector<vector<int>> res;
void dfs(int root, int target)
{
    if (target == nodes[root].weight && nodes[root].child.size() == 0)
    {
        temp.push_back(root);
        res.push_back(temp);
        temp.pop_back();
        return;
    }

    //非终点
    if (nodes[root].child.size() > 0)
    {
        int t = target;
        temp.push_back(root);
        t -= nodes[root].weight;
        for (int i = 0; i < nodes[root].child.size(); i++)
        {
            dfs(nodes[root].child[i], t);
        }
        temp.pop_back();
    }
}
bool cmp(int &a, int &b)
{
    return nodes[a].weight > nodes[b].weight;
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nodes[i].weight);
    }
    for (int i = 0; i < m; i++)
    {
        int id, k;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            int cid;
            scanf("%d", &cid);
            nodes[id].child.push_back(cid);
        }
        sort(nodes[id].child.begin(), nodes[id].child.end(), cmp);
    }
    dfs(00, s);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            if (j != 0)
                printf(" ");
            printf("%d", nodes[res[i][j]].weight);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}