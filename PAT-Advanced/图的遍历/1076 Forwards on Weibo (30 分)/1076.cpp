#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> followed;
vector<bool> isVisited;
int n, l;
int ans;
vector<int> tempLevel;
struct node
{
    int id;
    int layer;
};
void BFS(int u)
{
    queue<node> q;
    node start;
    start.id = u;
    start.layer = 0;
    q.push(start);
    isVisited[start.id] = true;
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        int s = top.id;
        for (int i = 0; i < followed[s].size(); i++)
        {
            node next;
            next.id = followed[s][i];
            next.layer = top.layer + 1;
            if (isVisited[next.id] == false && next.layer <= l)
            {
                ans++;
                q.push(next);
                isVisited[next.id] = true;
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &l);
    vector<int> temp;
    followed.assign(n + 1, temp);
    for (int i = 1; i <= n; i++)
    {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            int follow;
            scanf("%d", &follow);
            followed[follow].push_back(i);
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int id;
        scanf("%d", &id);
        ans = 0;
        isVisited.assign(n + 1, false);
        tempLevel.assign(n + 1, 0);
        BFS(id);
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}