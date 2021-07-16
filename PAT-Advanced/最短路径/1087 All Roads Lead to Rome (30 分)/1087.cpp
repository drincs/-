#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
int n, k, ed;
char name[4];
map<string, int> nameToId;
map<int, string> idToName;
struct Node
{
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis) {}
};
const int MAXV = 210;
const int INF = 0x3fffffff;
vector<Node> Adj[MAXV];
int weight[MAXV] = {0};
int d[MAXV];
bool inQ[MAXV] = {false};
set<int> pre[MAXV];
int num = 0;
int getId(char city[])
{
    if (nameToId.count(city) == 0)
    {
        idToName[num] = city;
        nameToId[city] = num++;
    }
    return nameToId[city];
}
void SPFA(int s)
{
    fill(inQ, inQ + MAXV, false);
    fill(d, d + MAXV, INF);
    d[s] = 0;
    queue<int> q;
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
            if (dis + d[u] < d[v])
            {
                d[v] = dis + d[u];
                pre[v].clear();
                pre[v].insert(u);
                if (!inQ[v])
                {
                    q.push(v);
                    inQ[v] = false;
                }
            }
            else if (dis + d[u] == d[v])
            {
                pre[v].insert(u);
                if (!inQ[v])
                {
                    q.push(v);
                    inQ[v] = false;
                }
            }
        }
    }
}
vector<vector<int>> paths;
vector<int> path;
int maxWeight = 0;
vector<vector<int>> maxWeightPaths;
int tw = 0;
void getPaths(int e)
{
    tw += weight[e];
    path.push_back(e);
    if (e == 0)
    {
        paths.push_back(path);
        if (maxWeight < tw)
        {
            maxWeight = tw;
            maxWeightPaths.clear();
            maxWeightPaths.push_back(path);
        }
        else if (maxWeight == tw)
        {
            maxWeightPaths.push_back(path);
        }
        return;
    }
    set<int>::iterator it = pre[e].begin();
    for (it; it != pre[e].end(); it++)
    {
        getPaths(*it);
        path.pop_back();
        tw -= weight[*it];
    }
}
bool cmp(vector<int> &a, vector<int> &b)
{
    return a.size() < b.size();
}
int main()
{
    scanf("%d %d %s", &n, &k, name);
    getId(name);
    for (int i = 1; i < n; i++)
    {
        int cw;
        scanf("%s %d", name, &cw);

        int id = getId(name);
        if (strcmp(name, "ROM") == 0)
        {
            ed = id;
        }
        weight[id] = cw;
    }
    for (int i = 0; i < k; i++)
    {
        char c1[4], c2[4];
        int dis;
        scanf("%s %s %d", c1, c2, &dis);
        int id1 = getId(c1);
        int id2 = getId(c2);
        Adj[id1].push_back(Node(id2, dis));
        Adj[id2].push_back(Node(id1, dis));
    }
    SPFA(0);
    getPaths(ed);
    sort(maxWeightPaths.begin(), maxWeightPaths.end(), cmp);
    printf("%d %d %d %d\n", paths.size(), d[ed], maxWeight, maxWeight / (maxWeightPaths[0].size() - 1));
    for (int j = maxWeightPaths[0].size() - 1; j >= 0; j--)
    {
        if (j != maxWeightPaths[0].size() - 1)
            printf("->");
        cout << idToName[maxWeightPaths[0][j]];
    }
    printf("\n");
    system("pause");
    return 0;
}