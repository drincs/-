#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int x;
    int y;
    int z;
};
vector<vector<vector<int>>> brain;
int M, N, L, T;
vector<vector<vector<bool>>> inq;
int ans = 0;
int X[6] = {-1, 0, 0, 0, 0, 1};
int Y[6] = {0, 1, -1, 0, 0, 0};
int Z[6] = {0, 0, 0, 1, -1, 0};
bool judge(node e)
{
    if (e.x >= 0 && e.x < M && e.y >= 0 && e.y < N && e.z >= 0 && e.z < L)
    {
        if (brain[e.z][e.x][e.y] == 1 && inq[e.z][e.x][e.y] == false)
        {
            return true;
        }
    }
    return false;
}
void bfs(node e)
{
    int valid = 0;
    queue<node> q;
    q.push(e);
    valid++;
    inq[e.z][e.x][e.y] = true;
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            node now;
            now.z = top.z + Z[i];
            now.x = top.x + X[i];
            now.y = top.y + Y[i];
            if (judge(now))
            {
                q.push(now);
                valid++;
                inq[now.z][now.x][now.y] = true;
            }
        }
    }
    if (valid >= T)
    {
        ans += valid;
    }
}
int main()
{
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for (int l = 0; l < L; l++)
    {
        vector<vector<int>> layer;
        vector<vector<bool>> inlayer;
        for (int i = 0; i < M; i++)
        {
            vector<int> temp;
            vector<bool> intemp(N, false);
            for (int j = 0; j < N; j++)
            {
                int val;
                scanf("%d", &val);
                temp.push_back(val);
            }
            layer.push_back(temp);
            inlayer.push_back(intemp);
        }
        brain.push_back(layer);
        inq.push_back(inlayer);
    }
    for (int l = 0; l < L; l++)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                node now;
                now.z = l;
                now.x = i;
                now.y = j;
                if (judge(now))
                {
                    bfs(now);
                }
            }
        }
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}