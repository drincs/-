#include <iostream>
#include <vector>
using namespace std;
struct node
{
    vector<int> child;
} nodes[100000];
int maxDepth = 0;
int maxCount = 0;
void calDepth(int root, int depth)
{
    if (depth > maxDepth)
    {
        maxDepth = depth;
        maxCount = 1;
    }
    else if (depth == maxDepth)
    {
        maxCount++;
    }
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
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%d", &id);
        if (id == -1)
        {
            root = i;
        }
        else
        {
            nodes[id].child.push_back(i);
        }
    }
    calDepth(root, 1);
    double highest = 1.0;
    double rate = 1.0;
    double grow = (100 + r) * 1.0 / 100;
    for (int i = 0; i < maxDepth; i++)
    {
        highest = p * rate;
        rate = rate * grow;
    }
    printf("%.2f %d\n", highest, maxCount);
    system("pause");
    return 0;
}