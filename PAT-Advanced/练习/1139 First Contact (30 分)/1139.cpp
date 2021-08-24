#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;
unordered_map<string, int> getId;
bool isFriend[10001][10001] = {false};
struct people
{
    string id;
    int gender = 1;
    vector<int> friends;
    vector<int> same;
};
vector<people> all;
struct pp
{
    int as;
    int bs;
    pp(int a, int b)
    {
        this->as = a;
        this->bs = b;
    }
};
bool cmp(pp a, pp b)
{
    if (all[a.as].id == all[b.as].id)
    {
        return all[a.bs].id < all[b.bs].id;
    }
    return all[a.as].id < all[b.as].id;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        if (getId.count(a) == 0)
        {
            getId.insert(make_pair(a, count));
            people tmp;
            tmp.id = a;
            if (a[0] == '-')
            {
                tmp.id = tmp.id.substr(1, 4);
                tmp.gender = -1;
            }
            all.push_back(tmp);
            count++;
        }
        if (getId.count(b) == 0)
        {
            getId.insert(make_pair(b, count));
            people tmp;
            tmp.id = b;
            if (b[0] == '-')
            {
                tmp.id = tmp.id.substr(1, 4);
                tmp.gender = -1;
            }
            all.push_back(tmp);
            count++;
        }
        if (a.length() == b.length())
        {
            all[getId[a]].same.push_back(getId[b]);
            all[getId[b]].same.push_back(getId[a]);
        }
        isFriend[getId[a]][getId[b]] = true;
        isFriend[getId[b]][getId[a]] = true;
    }
    int k;
    cin >> k;
    while (k--)
    {
        string a, b;
        cin >> a >> b;
        vector<int> seta, setb;
        if (getId.count(a) == 0 || getId.count(b) == 0)
        {
            printf("0\n");
            continue;
        }
        else
        {
            seta.assign(all[getId[a]].same.begin(), all[getId[a]].same.end());
            setb.assign(all[getId[b]].same.begin(), all[getId[b]].same.end());
            vector<pp> res;
            for (int i = 0; i < seta.size(); i++)
            {
                if (seta[i] == getId[a] || seta[i] == getId[b])
                {
                    continue;
                }
                //不可以直接找到
                for (int j = 0; j < setb.size(); j++)
                {

                    if (setb[j] == getId[a])
                        continue;
                    //同性不能是同一个朋友
                    if (isFriend[seta[i]][setb[j]] && seta[i] != setb[j])
                    {
                        res.push_back(pp(seta[i], setb[j]));
                    }
                }
            }
            printf("%d\n", res.size());
            sort(res.begin(), res.end(), cmp);
            for (int i = 0; i < res.size(); i++)
            {
                int a = res[i].as;
                int b = res[i].bs;
                cout << all[a].id << " " << all[b].id << endl;
            }
        }
    }
    system("pause");
    return 0;
}