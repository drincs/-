#include <iostream>
#include <map>
#include <vector>
using namespace std;
int num = 0;
map<string, int> names;
map<int, string> ids;
vector<vector<int>> graph;
vector<int> v_weight;
vector<bool> isArrived;
int member = 0;
int total = 0;
int head;
int n, k;
map<string, int> res;
int getId(string name)
{
    map<string, int>::iterator it = names.find(name);
    if (it == names.end())
    {
        names[name] = num++;
        ids[names[name]] = name;
    }
    return names[name];
}
void DFS(int u)
{
    member++;
    isArrived[u] = true;
    if (v_weight[u] > v_weight[head])
    {
        head = u;
    }
    for (int i = 0; i < n; i++)
    {
        if (graph[u][i] > 0)
        {
            total += graph[u][i];
            graph[u][i] = graph[i][u] = 0;
            if (isArrived[i] == false)
                DFS(i);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    v_weight.assign(2*n, 0);
    vector<int> temp;
    temp.assign(2*n, 0);
    graph.assign(2*n, temp);
    isArrived.assign(2*n, false);
    for (int i = 0; i < n; i++)
    {
        string name1, name2;
        int t;
        cin >> name1 >> name2 >> t;
        //获取映射关系
        int id1 = getId(name1);
        int id2 = getId(name2);
        v_weight[id1] += t;
        v_weight[id2] += t;
        graph[id1][id2] += t;
        graph[id2][id1] += t;
    }
    for (int i = 0; i < num; i++)
    {
        if (isArrived[i] == false)
        {
            member = 0;
            total = 0;
            head = i;
            DFS(i);
            //单块结束
            if (total > k && member > 2)
            {
                res[ids[head]] = member;
            }
        }
    }
    map<string, int>::iterator it = res.begin();
    cout << res.size() << endl;
    for (it; it != res.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    system("pause");
    return 0;
}