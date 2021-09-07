#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    vector<int> in;
    vector<int> out;
};
vector<node> v;
bool judge(vector<int> a, vector<node> vv)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (vv[a[i]].in.size() > 0)
        {
            return false;
        }
        else
        {
            int lenout = vv[a[i]].out.size();
            for (int j = 0; j < lenout; j++)
            {
                int q = vv[a[i]].out[j];
                vector<int>::iterator it = find(vv[q].in.begin(), vv[q].in.end(), a[i]);
                if (it != vv[q].in.end())
                {
                    vv[q].in.erase(it);
                }
            }
        }
    }
    return true;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    node t;
    v.assign(n + 1, t);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].out.push_back(b);
        v[b].in.push_back(a);
    }
    int q;
    scanf("%d", &q);
    vector<int> res;
    for (int i = 0; i < q; i++)
    {
        vector<int> test(n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &test[j]);
        }
        bool flag = judge(test, v);
        if (!flag)
        {
            res.push_back(i);
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}