#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
struct stu
{
    string id;
    int gp = -1, gf = -1, gm = -1, g = 0;
};
unordered_map<string, int> getIndex;
vector<stu> stus;
vector<int> pass;
bool cmp(int &a, int &b)
{
    if (stus[a].g == stus[b].g)
    {
        return stus[a].id < stus[b].id;
    }
    else
    {
        return stus[a].g > stus[b].g;
    }
}
int main()
{
    int p, m, n;
    scanf("%d%d%d", &p, &m, &n);
    int count = 0;
    for (int i = 0; i < p; i++)
    {
        string a;
        int gp;
        cin >> a;
        scanf("%d", &gp);
        if (gp >= 200)
        {
            stu temp;
            temp.id = a;
            temp.gp = gp;
            getIndex.insert(make_pair(a, count++));
            stus.push_back(temp);
        }
    }
    for (int i = 0; i < m; i++)
    {
        string id;
        int gm;
        cin >> id;
        scanf("%d", &gm);
        if (getIndex.count(id) > 0)
        {
            unordered_map<string, int>::iterator it = getIndex.find(id);
            stus[it->second].gm = gm;
        }
    }

    for (int i = 0; i < n; i++)
    {
        string id;
        int gf;
        cin >> id;
        scanf("%d", &gf);
        if (getIndex.count(id) > 0)
        {
            unordered_map<string, int>::iterator it = getIndex.find(id);
            stus[it->second].gf = gf;
            if (stus[it->second].gm > stus[it->second].gf)
            {
                stus[it->second].g = round(0.4 * stus[it->second].gm + 0.6 * stus[it->second].gf);
            }
            else
            {
                stus[it->second].g = stus[it->second].gf;
            }
        }
    }
    vector<int> pass;
    for (int i = 0; i < stus.size(); i++)
    {
        if (stus[i].g >= 60)
        {
            pass.push_back(i);
        }
    }
    sort(pass.begin(), pass.end(), cmp);
    for (int i = 0; i < pass.size(); i++)
    {
        stu it = stus[pass[i]];
        cout << it.id << " " << it.gp << " " << it.gm << " " << it.gf << " " << it.g << endl;
    }
    system("pause");
    return 0;
}