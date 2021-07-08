#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;
int Cmax, N, Sp, M, half;
const int MAXN = 501;
const int INF = 0x3fffffff;
struct Station
{
    int v, time;
    Station(int _v, int _time) : v(_v), time(_time) {}
};
vector<Station> Adj[MAXN];
int num[MAXN];
bool vis[MAXN] = {false};
int t[MAXN], out[MAXN], back[MAXN];
vector<int> pre[MAXN];
void Dijkstra(int s)
{
    fill(t, t + MAXN, INF);
    fill(out, out + MAXN, 0);
    fill(back, back + MAXN, 0);
    t[s] = 0;

    for (int i = 0; i < N; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < N; j++)
        {
            if (vis[j] == false && t[j] < MIN)
            {
                u = j;
                MIN = t[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int j = 0; j < Adj[u].size(); j++)
        {
            int v = Adj[u][j].v;
            int time = Adj[u][j].time;
            if (time + t[u] < t[v])
            {
                t[v] = time + t[u];
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if (time + t[u] == t[v])
            {
                pre[v].push_back(u);
            }
        }
    }
}
vector<vector<int>> paths;
vector<int> path;
void getPath(int s)
{
    if (s == 0)
    {
        path.push_back(s);
        paths.push_back(path);
        path.pop_back();
        return;
    }
    path.push_back(s);
    for (int i = 0; i < pre[s].size(); i++)
    {
        getPath(pre[s][i]);
    }
    path.pop_back();
}
int main()
{
    scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
    half = Cmax / 2;
    fill(num, num + MAXN, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i + 1]);
    }
    for (int i = 0; i < M; i++)
    {
        int a, b, time;
        scanf("%d%d%d", &a, &b, &time);
        Adj[a].push_back(Station(b, time));
        Adj[b].push_back(Station(a, time));
    }
    Dijkstra(0);
    getPath(Sp);
    int MINOUT = INF, MINBACK = INF, index = -1;
    for (int i = 0; i < paths.size(); i++)
    {
        int takeout = 0, tabkeback = 0;
        for (int j = paths[i].size() - 1; j >= 0; j--)
        {
            int v = paths[i][j];
            if (v != 0)
            {
                if (num[v] <= half)
                {
                    if (tabkeback >= half - num[v])
                    {
                        tabkeback -= half - num[v];
                    }
                    else
                    {
                        takeout += (half - num[v] - tabkeback);
                        tabkeback = 0;
                    }
                }
                else
                {
                    tabkeback += num[v] - half;
                }
            }
        }
        if (takeout < MINOUT)
        {
            MINOUT = takeout;
            MINBACK = tabkeback;
            index = i;
        }
        else if (takeout == MINOUT)
        {
            if (tabkeback < MINBACK)
            {
                MINBACK = tabkeback;
                index = i;
            }
        }
    }
    printf("%d", MINOUT);
    for (int i = paths[index].size() - 1; i >= 0; i--)
    {
        int v = paths[index][i];
        if (v == 0)
            printf(" %d", v);
        else
            printf("->%d", v);
    }
    printf(" %d\n", MINBACK);
    system("pause");
    return 0;
}