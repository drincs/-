#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
using namespace std;
const int MAXN = 510;
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
bool inQ[MAXN] = {false};
int inNum[MAXN];
void SPFA(int s)
{
    fill(d, d + MAXN, INF);
    memset(num, 0, sizeof(num));
    memset(inNum, 0, sizeof(inNum));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    num[s] = 1;
    w[s] = weight[s];
    queue<int> q;
    q.push(s);
    inNum[s]++;
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
            if (dis + d[u] < d[v])
            {
                d[v] = dis + d[u];
                w[v] = w[u] + weight[v];
                pre[v].clear();
                pre[v].insert(u);
                num[v] = num[u];
                if (inQ[v] == false)
                {
                    q.push(v);
                    inQ[v] = true;
                    inNum[v]++;
                    if (inNum[v] >= n)
                    {
                        //存在可达负环，本题不存在
                    }
                }
            }
            else if (dis + d[u] == d[v])
            {
                if (w[v] < w[u] + weight[v])
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
                if (inQ[v] == false)
                {
                    q.push(v);
                    inQ[v] = true;
                    inNum[v]++;
                    if (inNum[v] >= n)
                    {
                        //存在可达负环，本题不存在
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
    SPFA(C1);
    printf("%d %d\n", num[C2], w[C2]);
    system("pause");
    return 0;
}