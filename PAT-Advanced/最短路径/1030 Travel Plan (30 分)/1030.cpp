#include <iostream>
#include <string.h>
using namespace std;
const int INF = 1000000000;
const int MAXN = 501;
int n, m, s, D;
int map[MAXN][MAXN];
int d[MAXN];
int c[MAXN];
int minCost = INF;
int cost[MAXN][MAXN];
int pre[MAXN] = {-1};
bool vis[MAXN] = {false};
void Dijkstra(int s)
{
    fill(d, d + MAXN, INF);
    fill(c, c + MAXN, INF);
    d[s] = 0;
    c[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && map[u][v] < INF)
            {
                //中介点长度小于
                if (d[u] + map[u][v] < d[v])
                {
                    d[v] = d[u] + map[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }
                else if (d[u] + map[u][v] == d[v])
                {
                    if (c[u] + cost[u][v] < c[v])
                    {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}
void DFS(int e)
{
    if (pre[e] == s)
    {
        printf("%d", s);
        printf(" %d", e);
        return;
    }
    if (pre[e] != -1)
    {
        DFS(pre[e]);
    }
    printf(" %d", e);
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &D);
    fill(map[0], map[0] + MAXN * MAXN, INF);
    fill(cost[0], cost[0] + MAXN * MAXN, 0);

    for (int i = 0; i < m; i++)
    {
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        scanf("%d%d", &map[c1][c2], &cost[c1][c2]);
        map[c2][c1] = map[c1][c2];
        cost[c2][c1] = cost[c1][c2];
    }
    Dijkstra(s);
    DFS(D);
    printf(" %d %d\n", d[D], c[D]);
    system("pause");
    return 0;
}