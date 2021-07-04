#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<bool> isAdded;
vector<vector<int>> graph;
vector<int> tempHeight;
vector<int> res;
int maxHeight = 0;
int currentHeight = 0;
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    isAdded[u] = true;
    tempHeight[u] = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        vector<int>::iterator it = graph[top].begin();
        for (it; it != graph[top].end(); it++)
        {
            tempHeight[*it] = tempHeight[top] + 1;
            currentHeight = tempHeight[*it];
            if (isAdded[*it] == false)
            {
                q.push(*it);
                isAdded[*it] = true;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> temp;
    graph.assign(n + 1, temp);
    tempHeight.assign(n + 1, 0);
    isAdded.assign(n + 1, false);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isAdded[i] == false)
        {
            BFS(i);
            comp++;
        }
    }
    if (n == 1)
    {
        printf("1\n");
    }
    else
    {
        if (comp > 1)
        {
            printf("Error: %d components\n", comp);
        }
        else
        {
            if (currentHeight > maxHeight)
            {
                maxHeight = currentHeight;
                res.push_back(1);
            }
            //继续2-n
            for (int i = 2; i <= n; i++)
            {
                currentHeight = 0;
                tempHeight.assign(n + 1, 0);
                isAdded.assign(n + 1, false);
                BFS(i);
                if (currentHeight > maxHeight)
                {
                    maxHeight = currentHeight;
                    res.clear();
                    res.push_back(i);
                }
                else if (currentHeight == maxHeight)
                {
                    res.push_back(i);
                }
            }
            for (int i = 0; i < res.size(); i++)
            {
                printf("%d\n", res[i]);
            }
        }
    }
    system("pause");
    return 0;
}