#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
struct record
{
    char plate[8];
    int time;
    int status; //进0 出1 先进后出
};
bool cmp(record &a, record &b)
{
    if (strcmp(a.plate, b.plate) == 0)
    {
        if (a.time == b.time)
        {
            return a.status < b.status;
        }
        return a.time < b.time;
    }
    return strcmp(a.plate, b.plate) < 0;
}
bool cmpTime(record &a, record &b)
{
    return a.time < b.time;
}
int main()
{
    int n, k, maxTime = 0;
    vector<record> all;
    map<string, int> totalTime;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int h, m, s;
        record r;
        char status[4];
        scanf("%s %d:%d:%d %s", r.plate, &h, &m, &s, status);
        r.time = h * 3600 + m * 60 + s;
        if (status[0] == 'i')
            r.status = 0;
        else
            r.status = 1;
        all.push_back(r);
    }
    sort(all, all + n, cmp);
    vector<record> valid;
    record current = all[0];
    for (int i = 0; i < n;)
    {
        bool in = false, out = false;
        record in_record;
        while (strcmp(current.plate, all[i].plate) == 0)
        {
            //同一辆车的出入
            if (all[i].status == 1 && in)
            {
                out = true;
            }
            else if (all[i].status == 0)
            {
                in = true;
                //记录进入数据
                in_record = all[i];
            }
            else
            {
                in = false;
                out = false;
            }
            if (out && in)
            {
                //匹配
                valid.push_back(in_record);
                valid.push_back(all[i]);
                if (totalTime.count(current.plate) == 0)
                {

                    totalTime[current.plate] = 0;
                }
                totalTime[current.plate] += all[i].time - in_record.time;
                if (maxTime < totalTime[current.plate])
                {
                    maxTime = totalTime[current.plate];
                }
                in = false;
                out = false;
            }
            i++;
        }
        current = all[i];
    }
    sort(valid.begin(), valid.end(), cmpTime);
    int now = 0, carNum = 0;
    for (int i = 0; i < k; i++)
    {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int time = h * 3600 + m * 60 + s;
        for (now; now < valid.size() && valid[now].time <= time; now++)
        {
            if (valid[now].status == 0)
            {
                carNum++;
            }
            else
            {
                carNum--;
            }
        }
        printf("%d\n", carNum);
    }
    //输出停车总长最多的车牌号及停车时间
    map<string, int>::iterator it = totalTime.begin();
    for (it; it != totalTime.end(); it++)
    {
        if (it->second == maxTime)
        {
            printf("%s ", it->first);
        }
    }
    printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
    system("pause");
    return 0;
}