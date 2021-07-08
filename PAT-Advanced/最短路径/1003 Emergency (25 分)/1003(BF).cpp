#include <iostream>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
const int MAXN = 500;
const int INF = 1000000000;
struct Node
{
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis) {}
};
vector<Node> Adj[MAXN];
int weight[MAXN];
int d[MAXN], num[MAXN], w[MAXN];
set<int> pre[MAXN];
int n, m, C1, C2;
void Bellman(int s)
{
    fill(d, d + MAXN, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    num[s] = 1;
    w[s] = weight[s];
    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int j = 0; j < Adj[u].size(); j++)
            {
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if (dis + d[u] < d[v])
                {
                    d[v] = d[u] + dis;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                }
                else if (dis + d[u] == d[v])
                {
                    if (w[u] + weight[v] > w[v])
                    {
                        w[v] = w[u] + weight[v];
                    }
                    pre[v].insert(u);
                    num[v] = 0;
                    set<int>::iterator it = pre[v].begin();
                    for (it; it != pre[v].end(); it++)
                    {
                        num[v] += num[*it];
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &C1, &C2);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int c1, c2, dis;
        scanf("%d%d%d", &c1, &c2, &dis);
        Adj[c1].push_back(Node(c2, dis));
        Adj[c2].push_back(Node(c1, dis));
    }
    Bellman(C1);
    printf("%d %d\n", num[C2], w[C2]);
    system("pause");
    return 0;
}