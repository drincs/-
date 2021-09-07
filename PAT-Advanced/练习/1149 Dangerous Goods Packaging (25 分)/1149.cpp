#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, vector<int>> ic;
unordered_map<int, int> cc;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int id1, id2;
        scanf("%d%d", &id1, &id2);
        ic[id1].push_back(id2);
        ic[id2].push_back(id1);
        cc[id1] = 0;
        cc[id2] = 0;
    }
    while (m--)
    {
        int k;
        unordered_map<int, int> dd = cc;
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            int id;
            scanf("%d", &id);
            if (ic.count(id) > 0)
            {
                if (dd[id] == 0)
                {
                    dd[id] = 1;
                }
            }
        }
        unordered_map<int, vector<int>>::iterator it = ic.begin();
        bool flag = true;
        for (it; it != ic.end(); it++)
        {
            if (dd[it->first] > 0)
            {
                //判断不可打包列表中是否有存在的
                int q = it->first;
                vector<int>::iterator tt = (it->second).begin();
                for (tt; tt != (it->second).end(); tt++)
                {
                    if (dd[*tt] > 0)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    system("pause");
    return 0;
}