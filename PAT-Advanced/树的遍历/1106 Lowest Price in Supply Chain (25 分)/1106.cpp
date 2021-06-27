#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int depth;
    vector<int> child;
} nodes[100000];
vector<int> leaf;
void dfs(int root, int depth)
{
    nodes[root].depth = depth;
    for (int i = 0; i < nodes[root].child.size(); i++)
    {
        dfs(nodes[root].child[i], depth + 1);
    }
}
int main()
{
    int n;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        if (k == 0)
        {
            leaf.push_back(i);
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                int id;
                scanf("%d", &id);
                nodes[i].child.push_back(id);
            }
        }
    }
    dfs(0, 1);
    int num = 0, minDepth = 100001;
    for (int i = 0; i < leaf.size(); i++)
    {
        node n = nodes[leaf[i]];
        if (n.depth < minDepth)
        {
            minDepth = n.depth;
            num = 1;
        }
        else if (n.depth == minDepth)
        {
            num++;
        }
    }
    double ans = 0.0;
    double grow = (100 + r) * 1.0 / 100;
    double rate = 1.0;
    for (int i = 0; i < minDepth; i++)
    {
        ans = p * rate;
        rate = rate * grow;
    }
    printf("%.4f %d\n", ans, num);
    system("pause");
    return 0;
}