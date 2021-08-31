#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <string.h>
#include <set>
using namespace std;
struct school
{
    string id;
    int tws = 0;
    double dtws = 0;
    int ns = 0;
    int rank;
    set<int> stu;
    school(string id)
    {
        this->id = id;
    }
};
vector<school> all;
unordered_map<string, int> getId;

unordered_map<string, int> getSid;
bool cmp(school &a, school &b)
{
    if (a.tws == b.tws)
    {
        if (a.stu.size() == b.stu.size())
        {
            return a.id < b.id;
        }
        return a.stu.size() < b.stu.size();
    }
    return a.tws > b.tws;
}
int main()
{
    int n;
    int count = 0;
    int snum;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string sid, id;
        double score;
        cin >> sid >> score >> id;
        for (int j = 0; j < id.length(); j++)
        {
            if (id[j] >= 'A' && id[j] <= 'Z')
                id[j] = id[j] - 'A' + 'a';
        }
        if (getId.count(id) == 0)
        {
            getId.insert(make_pair(id, count));
            all.push_back(school(id));
            count++;
        }
        int iid = getId[id];
        if (sid[0] == 'A')
        {
            all[iid].dtws += score * 1.0;
        }
        else if (sid[0] == 'B')
        {
            all[iid].dtws += score * 1.0 / 1.5;
        }
        else if (sid[0] == 'T')
        {
            all[iid].dtws += score * 1.5;
        }
        if (getSid.count(sid) == 0)
        {
            getSid.insert(make_pair(sid, snum++));
        }

        all[iid].stu.insert(getSid[sid]);
    }
    for (int i = 0; i < count; i++)
    {
        all[i].tws = (int)all[i].dtws;
    }
    sort(all.begin(), all.end(), cmp);
    int rank = 1;
    int now = 0;
    if (count > 0)
        now = all[0].tws;
    cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        if (now != all[i].tws)
            rank = i + 1;
        now = all[i].tws;
        cout << rank << " " << all[i].id << " " << now << " " << all[i].stu.size() << endl;
    }
    system("pause");
    return 0;
}