#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
const int MAXN = 10011;
const int open_T = 8 * 60 * 60;
const int close_T = 21 * 60 * 60;
struct player
{
    int arrive;
    int served = close_T;
    int p;
    int tag;
};
struct table
{
    int update_T = open_T;
    int tag = 0;
    int served = 0;
};
table tables[101];
player players[MAXN];
int N, K, M;
int convertT(int h, int m, int s)
{
    return (h * 60 + m) * 60 + s;
}
vector<int> queue;
vector<int> res;
bool cmp(int &a, int &b)
{
    return players[a].arrive < players[b].arrive;
}
//最早空闲的最小编号的桌
int getTable()
{
    int update_T = tables[1].update_T;
    int tid = 1;
    for (int i = 2; i <= K; i++)
    {
        if (tables[i].update_T < update_T)
        {
            tid = i;
            update_T = tables[i].update_T;
        }
    }
    return tid;
}
bool cmpres(int &a, int &b)
{
    return players[a].served < players[b].served;
}
int main()
{
    int count = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        int h, m, s, p, tag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &tag);
        int t = convertT(h, m, s);
        if (t < close_T)
        {
            players[count].arrive = t;
            if (p > 120)
                p = 120;
            players[count].p = p * 60;
            players[count].tag = tag;
            queue.push_back(count);
            count++;
        }
    }
    scanf("%d%d", &K, &M);
    for (int i = 1; i <= M; i++)
    {
        int id;
        scanf("%d", &id);
        tables[id].tag = 1;
    }
    //按到达时间排序
    sort(queue.begin(), queue.end(), cmp);
    // 球桌最早空闲的最小编号tid
    int tid = getTable();
    while (!queue.empty() && tables[tid].update_T < close_T)
    {
        vector<int>::iterator it = queue.begin();
        //桌子空了的时候无人排队
        if (players[*it].arrive >= tables[tid].update_T)
        {
            // 球桌状态重新更新为下一玩家到达时的状态
            //（队伍空置时间长 更新桌子状态）
            for (int i = 1; i <= K; i++)
            {
                //到达前结束的将空闲时间更新为第一个玩家到达的时间
                if (tables[i].update_T <= players[*it].arrive)
                {
                    tables[i].update_T = players[*it].arrive;
                    //玩家非vip 直接安排第一张此刻空闲的桌子
                    // if (!in && players[*it].tag == 0)
                    // {
                    //     players[*it].served = tables[i].update_T;
                    //     tables[i].update_T += players[*it].p;
                    //     tables[i].served++;
                    //     in = true;
                    // }
                    // // 玩家为VIP
                    // else if (!in && tables[i].tag == 1 && players[*it].tag == 1)
                    // {
                    //     //若此桌vip桌，则安排进入
                    //     players[*it].served = tables[i].update_T;
                    //     tables[i].update_T += players[*it].p;
                    //     tables[i].served++;
                    //     in = true;
                    // }
                }
            }
            //vip玩家未找到vip球桌视为普通玩家
            // if (!in)
            // {
            //     //直接拿一桌
            //     tid = getTable();
            //     players[*it].served = tables[tid].update_T;
            //     tables[tid].update_T += players[*it].p;
            //     tables[tid].served++;
            // }
            tid = getTable();
            //下一空闲球桌
            //tid = getTable();
            // res.push_back(*it);
            // queue.erase(it);
        }
        // else
        // {
        // 已有部分玩家在排队
        for (it; it != queue.end() && players[*it].arrive <= tables[tid].update_T; it++)
        {
            if (players[*it].tag)
            {
                //时间内第一个vip
                break;
            }
        }
        //是否vip桌
        if (tables[tid].tag)
        {
            //安排上述it
            players[*it].served = tables[tid].update_T;
            tables[tid].update_T += players[*it].p;
            res.push_back(*it);
            queue.erase(it);
        }
        else
        {
            //安排第一个
            vector<int>::iterator fit = queue.begin();
            // if (players[*fit].arrive <= tables[tid].update_T)
            // {
            players[*fit].served = tables[tid].update_T;
            tables[tid].update_T += players[*fit].p;
            // }
            // else
            // {

            //     players[*fit].served = players[*fit].arrive;
            //     tables[tid].update_T = players[*fit].arrive + players[*it].p;
            // }
            res.push_back(*fit);
            queue.erase(fit);
        }
        tables[tid].served++;
        tid = getTable();
        //}
    }
    sort(res.begin(), res.end(), cmpres);
    for (int i = 0; i < res.size() && players[res[i]].served < close_T; i++)
    {
        int pid = res[i];
        int wait = int(1.0 * (players[pid].served - players[pid].arrive) / 60 + 0.5);
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", players[pid].arrive / 3600, players[pid].arrive / 60 % 60, players[pid].arrive % 60, players[pid].served / 3600, players[pid].served / 60 % 60, players[pid].served % 60, wait);
    }
    for (int i = 1; i <= K; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", tables[i].served);
    }
    printf("\n");
    system("pause");
    return 0;
}