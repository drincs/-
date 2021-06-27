#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int depth;
    int amount;
    vector<int> child;
} nodes[100000];
vector<int> leaf;
int maxDepth = 0;
vector<double> pr;
void calDepth(int root, int depth)
{
    if (depth > maxDepth)
    {
        maxDepth = depth;
    }
    nodes[root].depth = depth;
    for (int i = 0; i < nodes[root].child.size(); i++)
    {
        calDepth(nodes[root].child[i], depth + 1);
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
            scanf("%d", &nodes[i].amount);
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
    calDepth(0, 1);
    double temp = (100 + r) * 1.0 / 100;
    pr.push_back(p);
    for (int i = 0; i < maxDepth; i++)
    {
        pr.push_back(p * temp);
        p = p * temp;
    }
    double ans = 0;
    for (int i = 0; i < leaf.size(); i++)
    {
        int id = leaf[i];
        ans += pr[nodes[id].depth - 1] * nodes[id].amount;
    }
    printf("%.1f\n", ans);
    system("pause");
    return 0;
}