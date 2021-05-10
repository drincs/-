#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct person
{
    int id;
    int talent;
    int virtue;
    int total;
    int type; //1 圣人 2君子 3愚人 4小人
};
bool cmp(person &a, person &b)
{
    if (a.type == b.type)
    {
        if (a.total == b.total)
        {
            if (a.virtue == b.virtue)
            {
                return a.id < b.id;
            }
            return a.virtue > b.virtue;
        }
        return a.total > b.total;
    }
    return a.type < b.type;
}
int main()
{
    int n, l, h;
    scanf("%d%d%d", &n, &l, &h);
    vector<person> list;
    for (int i = 0; i < n; i++)
    {
        person a;
        scanf("%d%d%d", &a.id, &a.virtue, &a.talent);
        a.total = a.talent + a.virtue;

        if (a.talent >= h && a.virtue >= h)
        {
            a.type = 1;
        }
        else if (a.virtue >= h && a.talent >= l)
        {
            a.type = 2;
        }
        else if (a.talent >= l && a.virtue >= l)
        {
            if (a.talent > a.virtue)
                a.type = 4;
            else
                a.type = 3;
        }
        else
        {
            a.type = 0;
        }
        if (a.type > 0)
        {
            list.push_back(a);
        }
    }
    sort(list.begin(), list.end(), cmp);
    printf("%d\n", list.size());
    for (int i = 0; i < list.size(); i++)
    {
        printf("%d %d %d\n", list[i].id, list[i].virtue, list[i].talent);
    }
    system("pause");
    return 0;
}