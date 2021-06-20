#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct card
{
    char num[14];
    int score = 0;
};
struct site
{
    int sitenum = 0;
    int count = 0;
    int total = 0;
};
vector<card> all;
map<char, vector<int>> type1;
map<int, site> type2;
map<int, map<int, site>> type3;
bool cmp1(int &a, int &b)
{
    if (all[a].score == all[b].score)
    {
        return strcmp(all[a].num, all[b].num) < 0;
    }
    else
    {
        return all[a].score > all[b].score;
    }
};
bool cmp3(site &a, site &b)
{
    if (a.count == b.count)
    {
        return a.sitenum < b.sitenum;
    }
    else
        return a.count > b.count;
};
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        card t;
        scanf("%s%d", t.num, &t.score);
        all.push_back(t);
        //分类型
        type1[t.num[0]].push_back(i);
        int sitenum = 0;
        for (int i = 1; i < 4; i++)
        {
            sitenum = sitenum * 10 + (t.num[i] - '0');
        }
        //分考场
        type2[sitenum].sitenum = sitenum;
        type2[sitenum].count++;
        type2[sitenum].total += t.score;
        //分日期
        int time = 0;
        for (int i = 4; i < 10; i++)
        {
            time = time * 10 + t.num[i] - '0';
        }
        type3[time][sitenum].sitenum = sitenum;
        type3[time][sitenum].count++;
        type3[time][sitenum].total += t.score;
    }
    for (int i = 0; i < m; i++)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            char level;
            scanf(" %c", &level);
            //分数降序 学号升序
            sort(type1[level].begin(), type1[level].end(), cmp1);

            vector<int>::iterator it = type1[level].begin();
            printf("Case %d: %d %c\n", i + 1, type, level);
            if (it == type1[level].end())
            {
                printf("NA\n");
            }
            for (it; it != type1[level].end(); it++)
            {
                printf("%s %d\n", all[*it].num, all[*it].score);
            }
        }
        if (type == 2)
        {
            int sitenum;
            scanf("%d", &sitenum);
            printf("Case %d: %d %03d\n", i + 1, type, sitenum);
            if (type2[sitenum].count == 0)
            {
                printf("NA\n");
            }
            else
                printf("%d %d\n", type2[sitenum].count, type2[sitenum].total);
        }
        if (type == 3)
        {
            int time;
            scanf("%d", &time);
            printf("Case %d: %d %06d\n", i + 1, type, time);
            vector<site> tmp;
            map<int, site>::iterator it = type3[time].begin();
            for (it; it != type3[time].end(); it++)
            {
                tmp.push_back(it->second);
            }
            if (tmp.size() == 0)
            {
                printf("NA\n");
            }
            else
            {
                sort(tmp.begin(), tmp.end(), cmp3);
                vector<site>::iterator st = tmp.begin();
                for (st; st != tmp.end(); st++)
                {
                    printf("%d %d\n", st->sitenum, st->count);
                }
            }
        }
    }
    system("pause");
    return 0;
}