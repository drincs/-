#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int MAXN = 500;
const int INF = 1000000000;
int weight[MAXN];
int cost[MAXN][MAXN];
int d[MAXN], num[MAXN], w[MAXN];
bool vis[MAXN] = {false};
int n, m, C1, C2;
void Dijkstra(int s)
{
    fill(d, d + MAXN, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    //执行n次
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        //找未访问结点中距离最近的
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
            //中间点可达的下一点 可以看是否需要更新路径
            if (vis[v] == false && cost[u][v] != INF)
            {
                if (d[u] + cost[u][v] < d[v])
                {
                    d[v] = d[u] + cost[u][v];
                    w[v] = w[u] + weight[v];
                    //到达该点的路径一定与到达中介点的路径条数相同
                    num[v] = num[u];
                }
                else if (d[u] + cost[u][v] == d[v])
                {
                    if (w[u] + weight[v] > w[v])
                    {
                        w[v] = w[u] + weight[v];
                    }
                    num[v] += num[u];
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
    fill(cost[0], cost[0] + MAXN * MAXN, INF);
    for (int i = 0; i < m; i++)
    {
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        scanf("%d", &cost[c1][c2]);
        cost[c2][c1] = cost[c1][c2];
    }
    Dijkstra(C1);
    printf("%d %d\n", num[C2], w[C2]);
    system("pause");
    return 0;
}