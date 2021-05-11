#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
struct student
{
    int id;
    int C;
    int M;
    int E;
    int A;
};
struct ranks
{
    char name;
    int rank;
    ranks(char name, int r)
    {
        this->name = name;
        this->rank = r;
    }
};
bool cmp1(student &a, student &b)
{
    return a.C > b.C;
}
bool cmp2(student &a, student &b)
{
    return a.M > b.M;
}
bool cmp3(student &a, student &b)
{
    return a.E > b.E;
}
bool cmp4(student &a, student &b)
{
    return a.A > b.A;
}
bool cmp(ranks &a, ranks &b)
{
    if (a.rank == b.rank)
    {
        return a.name < b.name;
    }
    return a.rank < b.rank;
}
int main()
{
    int n, m;
    vector<student> stu;
    unordered_map<string, vector<ranks>> rankList;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        student a;
        scanf("%d%d%d%d", &a.id, &a.C, &a.M, &a.E);
        a.A = (a.C + a.M + a.E);
        stu.push_back(a);
        vector<ranks> r;
        rankList.insert(make_pair(to_string(a.id), r));
    }
    sort(stu.begin(), stu.end(), cmp1);
    int t = 1;
    int c = stu[0].C;
    for (int i = 0; i < n; i++)
    {
        if (c > stu[i].C)
        {
            c = stu[i].C;
            t = i + 1;
        }
        rankList[to_string(stu[i].id)].push_back(ranks('C', t));
    }
    sort(stu.begin(), stu.end(), cmp2);
    t = 1;
    c = stu[0].M;
    for (int i = 0; i < n; i++)
    {
        if (c > stu[i].M)
        {
            c = stu[i].M;
            t = i + 1;
        }
        rankList[to_string(stu[i].id)].push_back(ranks('D', t));
    }
    sort(stu.begin(), stu.end(), cmp3);
    t = 1;
    c = stu[0].E;
    for (int i = 0; i < n; i++)
    {
        if (c > stu[i].E)
        {
            c = stu[i].E;
            t = i + 1;
        }
        rankList[to_string(stu[i].id)].push_back(ranks('E', t));
    }
    sort(stu.begin(), stu.end(), cmp4);
    t = 1;
    c = stu[0].A;
    for (int i = 0; i < n; i++)
    {
        if (c > stu[i].A)
        {
            c = stu[i].A;
            t = i + 1;
        }
        rankList[to_string(stu[i].id)].push_back(ranks('A', t));
    }
    for (int i = 0; i < m; i++)
    {
        int query;
        scanf("%d", &query);
        unordered_map<string, vector<ranks>>::iterator it = rankList.find(to_string(query));
        if (it != rankList.end())
        {
            //
            sort(it->second.begin(), it->second.end(), cmp);
            ranks res(it->second.begin()->name, it->second.begin()->rank);
            printf("%d %c\n", res.rank, res.name == 'D' ? 'M' : res.name);
        }
        else
        {
            printf("N/A\n");
        }
    }
    system("pause");
    return 0;
}