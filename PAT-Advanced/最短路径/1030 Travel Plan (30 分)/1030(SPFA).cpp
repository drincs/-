#include <iostream>
#include <vector>
#include <set>
#include <string.h>
#include <queue>
using namespace std;
int n, m, st, ed;
struct Node
{
    int v, dis, cost;
    Node(int _v, int _dis, int _cost) : v(_v), dis(_dis), cost(_cost) {}
};
const int MAXN = 501;
const int INF = 0x3fffffff;
vector<Node> Adj[MAXN];
int d[MAXN];
int c[MAXN];
bool inQ[MAXN] = {false};
int pre[MAXN];
void SPFA(int s)
{
    fill(d, d + MAXN, INF);
    fill(c, c + MAXN, INF);
    queue<int> q;
    d[s] = 0;
    c[s] = 0;
    q.push(s);
    inQ[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inQ[u] = false;
        for (int i = 0; i < Adj[u].size(); i++)
        {
            int v = Adj[u][i].v;
            int dis = Adj[u][i].dis;
            int cost = Adj[u][i].cost;
            if (dis + d[u] < d[v])
            {
                d[v] = dis + d[u];
                c[v] = c[u] + cost;
                pre[v] = u;
                if (!inQ[v])
                {
                    q.push(v);
                    inQ[v] = true;
                }
            }
            else if (dis + d[u] == d[v])
            {
                if (c[v] > c[u] + cost)
                {
                    c[v] = c[u] + cost;
                    pre[v] = u;
                }
                if (!inQ[v])
                {
                    q.push(v);
                    inQ[v] = true;
                }
            }
        }
    }
}
void DFS(int s)
{
    if (s == st)
    {
        printf("%d", s);
        return;
    }
    DFS(pre[s]);
    printf(" %d", s);
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for (int i = 0; i < m; i++)
    {
        int a, b, dis, cost;
        scanf("%d%d%d%d", &a, &b, &dis, &cost);
        Adj[a].push_back(Node(b, dis, cost));
        Adj[b].push_back(Node(a, dis, cost));
    }
    SPFA(st);
    DFS(ed);
    printf(" %d %d\n", d[ed], c[ed]);
    system("pause");
    return 0;
}