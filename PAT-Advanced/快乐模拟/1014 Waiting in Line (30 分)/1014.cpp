#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int open_T = 8 * 60; //min
const int close_T = 17 * 60;
struct window
{
    int id;
    int update_T;
    queue<int> line;
};
struct customer
{
    int id;
    int T;
    int served_T = close_T;
};

int N, M, K, Q;
int pos = 1;
customer customers[1001];
window windows[21];
int findShort()
{
    int id = 1, min_line = windows[1].line.size();
    for (int i = 2; i <= N; i++)
    {
        if (windows[i].line.size() < min_line)
        {
            min_line = windows[i].line.size();
            id = i;
        }
    }
    return id;
}
void updateLine()
{
    int id = 1, update_T = windows[1].update_T;
    for (int i = 2; i <= N; i++)
    {
        if (windows[i].update_T < update_T)
        {
            update_T = windows[i].update_T;
            id = i;
        }
    }
    windows[id].line.pop();
    if (!windows[id].line.empty())
    {
        int cid = windows[id].line.front();
        customers[cid].served_T = update_T;
        windows[id].update_T += customers[cid].T;
        if (pos <= K)
            windows[id].line.push(pos++);
    }
    else
    {
        if (pos <= K)
        {
            customers[pos].served_T = windows[id].update_T;
            windows[id].update_T += customers[pos].T;
            windows[id].line.push(pos++);
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    for (int i = 1; i <= K; i++)
    {
        scanf("%d", &customers[i].T);
    }
    for (int i = 1; i <= N; i++)
    {
        windows[i].update_T = open_T;
        // for (int j = 0; j * N + i <= N * M && j * N + i <= K; j++)
        //     windows[i].line.push(j * N + i);
    }
    //pos = N * M + 1;
    while (pos <= K)
    {
        int id = findShort();
        if (windows[id].line.size() == M)
        {
            //更新并安排入队
            updateLine();
        }
        else
        { //入队
            windows[id].line.push(pos);
            if (windows[id].line.size() == 1)
            {
                customers[pos].served_T = windows[id].update_T;
                windows[id].update_T += customers[pos].T;
            }
            pos++;
        }
    }
    //处理黄线内剩余队伍
    for (int i = 1; i <= N; i++)
    {
        if (!windows[i].line.empty())
            windows[i].line.pop();
        while (!windows[i].line.empty())
        {
            int cid = windows[i].line.front();
            customers[cid].served_T = windows[i].update_T;
            windows[i].update_T += customers[cid].T;
            windows[i].line.pop();
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int q;
        scanf("%d", &q);
        if (customers[q].served_T < close_T)
        {
            int finish = customers[q].served_T + customers[q].T;
            printf("%02d:%02d\n", finish / 60, finish % 60);
        }
        else
        {
            printf("Sorry\n");
        }
    }
    system("pause");
    return 0;
}