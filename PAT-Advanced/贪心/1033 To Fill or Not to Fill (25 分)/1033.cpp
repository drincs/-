#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct station
{
    int id;
    double x;
    double price;
};
bool cmp(station &a, station &b)
{
    if (a.x == b.x)
    {
        return a.price < b.price;
    }
    return a.x < b.x;
}
int main()
{
    double Cmax, D, Davg;
    int n;
    station stations[501];
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &stations[i].price, &stations[i].x);
    }
    //加入终点
    stations[n].x = D;
    stations[n].price = 0;
    sort(stations, stations + n + 1, cmp);

    //起点
    int now = 0;
    double Cpos = 0;
    double Dmax = Cmax * Davg;
    double num, need, total = 0;
    if (stations[now].x != 0)
    {
        printf("The maximum travel distance = 0.00\n");
    }
    else
    {
        //寻找下一个加油站，直到到达终点或者到不了
        while (now < n)
        {
            int next = -1;
            //下一次油价初始值，视有没有找到（到达）采不采用
            double nextPrice = stations[now + 1].price + 1;
            for (int i = now + 1; i <= n && stations[i].x <= stations[now].x + Dmax; i++)
            {
                if (nextPrice > stations[i].price)
                {
                    //更新下一次油价低值
                    nextPrice = stations[i].price;
                    next = i;
                    if (nextPrice < stations[now].price)
                    {
                        //比现在的更便宜,直接到这里
                        break;
                    }
                }
            }
            if (next == -1)
            {
                break;
            }
            //移动到next
            need = (stations[next].x - stations[now].x) / Davg;
            if (nextPrice < stations[now].price)
            {
                //加足够的到next
                if (Cpos >= need)
                {
                    Cpos -= need;
                }
                else
                {
                    //不够
                    num = need - Cpos;
                    Cpos = 0;
                    total += num * stations[now].price;
                }
            }
            else
            {
                //加满
                num = Cmax - Cpos;
                Cpos = Cmax - need;
                total += num * stations[now].price;
            }
            now = next;
        }
        if (stations[now].x == D)
        {

            printf("%.2f\n", total);
        }
        else
        {
            printf("The maximum travel distance = %.2f\n", stations[now].x + Dmax);
        }
    }
    system("pause");
    return 0;
}