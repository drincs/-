#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n, m, k, ds;
struct Node
{
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis) {}
};
const int MAXV = 1020;
vector<Node> Adj[MAXV];
vector<int> G;
const int INF = 0x3fffffff;
int totalDis = INF;
int MINDis = 0;
int idx = -1;
int d[MAXV];
bool inQ[MAXV];
void SPFA(int s)
{
    fill(d, d + MAXV, INF);
    fill(inQ, inQ + MAXV, false);
    d[s] = 0;
    inQ[s] = true;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inQ[u] = false;
        for (int i = 0; i < Adj[u].size(); i++)
        {
            int v = Adj[u][i].v;
            int dis = Adj[u][i].dis;
            if (dis + d[u] < d[v])
            {
                d[v] = dis + d[u];
                if (!inQ[v])
                {
                    Q.push(v);
                    inQ[v] = true;
                }
            }
        }
    }
    int total = 0, MIN = INF;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] > ds)
        {
            return;
        }
        else
        {
            if (d[i] < MIN)
            {
                MIN = d[i];
            }
            total += d[i];
        }
    }
    if (MIN != INF && MIN > MINDis)
    {
        totalDis = total;
        idx = s;
        MINDis = MIN;
    }
    else if (MIN == MINDis)
    {
        if (total < totalDis)
        {
            totalDis = total;
            idx = s;
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    for (int i = 0; i < k; i++)
    {
        char p1[5], p2[5];
        int dist;
        scanf("%s%s%d", p1, p2, &dist);
        int r1, r2;
        if (p1[0] == 'G')
        {
            r1 = 1000;
            if (p1[1] == '1' && p1[2] == '0')
                r1 += 10;
            else
                r1 += p1[1] - '0';
        }
        else
        {
            r1 = atoi(p1);
        }
        if (p2[0] == 'G')
        {
            r2 = 1000;
            if (p2[1] == '1' && p2[2] == '0')
                r2 += 10;
            else
                r2 += p2[1] - '0';
        }
        else
        {
            r2 = atoi(p2);
        }
        Adj[r1].push_back(Node(r2, dist));
        Adj[r2].push_back(Node(r1, dist));
    }
    for (int i = 1; i <= m; i++)
    {
        SPFA(1000 + i);
    }
    if (totalDis != INF)
    {
        printf("G%d\n", idx - 1000);
        printf("%.1f %.1f\n", MINDis * 1.0, totalDis * 1.0 / n);
    }
    else
    {
        printf("No Solution\n");
    }
    system("pause");
    return 0;
}