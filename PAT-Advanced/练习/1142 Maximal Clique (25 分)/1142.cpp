#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int nv, ne;
    scanf("%d%d", &nv, &ne);
    vector<int> tmp;
    vector<vector<int>> vertices(nv + 1, tmp);
    bool arr[201][201] = {false};
    for (int i = 0; i < ne; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        vertices[a].push_back(b);
        vertices[b].push_back(a);
        arr[a][b] = true;
        arr[b][a] = true;
    }
    int k;
    scanf("%d", &k);
    while (k--)
    {
        int m;
        scanf("%d", &m);
        vector<int> set(m, 0);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &set[i]);
        }
        //isClique(set);
        bool isClique = true;
        vector<int> expend(nv + 1, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < vertices[set[i]].size(); j++)
            {
                expend[vertices[set[i]][j]]++;
            }
            for (int j = i + 1; j < m; j++)
            {
                if (!arr[set[i]][set[j]])
                {
                    isClique = false;
                    break;
                }
            }
        }
        // vector<int> remain;
        // vector<int> expend;
        // remain.assign(set.begin(),set.end());
        // queue<int> next;
        // //从1点出发 标记访问 到达所有可达点
        // vector<int>::iterator it=remain.begin();
        // next.push(*it);
        // remain.erase(it);
        // //结束条件
        // while(!next.empty()){
        //     int top=next.front();
        //     next.pop();
        //     for(int i=0;i<vertices[top].size();i++){
        //         expend.push_back(vertices[top][i]);
        //     }
        //     for(it;it!=remain.end();){
        //         if(arr[*it][top]){
        //             next.push(*it);
        //             remain.erase(it);
        //         }else{
        //             it++;
        //         }
        //     }
        // }
        if (!isClique)
        {
            printf("Not a Clique\n");
        }
        else
        {
            //max
            bool isMax = true;
            for (int i = 1; i <= nv; i++)
            {
                if (expend[i] == m)
                {
                    isMax = false;
                    break;
                }
            }
            if (isMax)
            {
                printf("Yes\n");
            }
            else
            {
                printf("Not Maximal\n");
            }
        }
    }
    system("pause");
    return 0;
}