#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000;
int concern = 0;
int n, m, k;
vector<bool> isArrived;
vector<vector<int>> graph;
void DFS(int u)
{
    if (u == concern)
    {
        return;
    }
    isArrived[u] = true;
    for (int i = 1; i <= n; i++)
    {
        if (graph[u][i] == 1 && isArrived[i] == false)
        {
            DFS(i);
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    vector<int> temp;
    temp.assign(n + 1, -1);
    graph.assign(n + 1, temp);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for (int i = 0; i < k; i++)
    {

        isArrived.assign(n + 1, false);
        scanf("%d", &concern);
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (isArrived[j] == false && j != concern)
            {
                DFS(j);
                ans++;
            }
        }
        printf("%d\n", ans - 1);
    }

    system("pause");
    return 0;
}