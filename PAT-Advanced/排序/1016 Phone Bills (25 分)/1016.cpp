#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct record
{
    char name[21];
    int M;
    int d;
    int h;
    int m;
    int status;
};

bool cmp(record &a, record &b)
{
    if (strcmp(a.name, b.name) == 0)
    {
        if (a.d == b.d)
        {
            if (a.h == b.h)
            {
                if (a.m == b.m)
                {
                    return a.status < b.status;
                }
                return a.m < b.m;
            }
            return a.h < b.h;
        }
        return a.d < b.d;
    }
    return strcmp(a.name, b.name) < 0;
}
int main()
{
    int n;
    int rate[24] = {0};
    for (int i = 0; i < 24; i++)
    {
        scanf("%d", &rate[i]);
    }
    vector<record> records;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        record temp;
        char action[10];
        getchar();
        scanf("%s %d:%d:%d:%d %s", temp.name, &temp.M, &temp.d, &temp.h, &temp.m, action);
        if (action[1] == 'f')
        {
            temp.status = 0;
        }
        else
            temp.status = 1;
        records.push_back(temp);
    }
    sort(records.begin(), records.end(), cmp);
    //逐人输出通话记录及账单金额
    record current = records[0];

    for (int i = 1; i < records.size();)
    {
        bool hangon = false;
        bool hangout = false;
        if (current.status == 1)
            hangon = true;
        vector<record> bills;
        double total = 0;
        while (strcmp(current.name, records[i].name) == 0)
        {
            if (records[i].status)
            {
                //接通 为新的开始
                hangon = true;
                current = records[i];
                hangout = false;
            }
            else
            {
                //挂断
                hangout = true;
            }
            //匹配的通话记录
            if (hangon && hangout)
            {
                bills.push_back(current);
                bills.push_back(records[i]);
                hangon = false;
                hangout = false;
            }
            i++;
        }
        //当前人已匹配完成
        //姓名 月份
        if (bills.size() > 0)
            printf("%s %02d\n", current.name, current.M);
        //每条记录 总时长 金额
        for (int j = 0; j < bills.size(); j += 2)
        {
            //每条费用
            double fare = 0;
            //计费规则 每个小时不相同 需要按各小时的分钟数计算
            int minutes = 0;
            record start = bills[j];
            record end = bills[j + 1];
            while (start.d < end.d || start.h < end.h || start.m < end.m)
            {
                start.m++;
                minutes++;
                fare += rate[start.h];
                if (start.m >= 60)
                {
                    start.h += start.m / 60;
                    start.m %= 60;
                }
                if (start.h >= 24)
                {
                    start.d += start.h / 24;
                    start.h %= 24;
                }
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", bills[j].d, bills[j].h, bills[j].m, end.d, end.h, end.m, minutes, fare / 100);
            total += fare;
        }
        if (bills.size() > 0)
            printf("Total amount: $%.2f\n", total / 100);
        //下一个人
        current = records[i];
        i++;
    }
    system("pause");
    return 0;
}