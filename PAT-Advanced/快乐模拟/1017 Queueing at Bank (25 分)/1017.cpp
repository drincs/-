#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 10001;
const int open_T = 8 * 60 * 60;
const int close_T = 17 * 60 * 60;
struct customer
{
    int T;
    int P;
};
int window[101];
customer customers[MAXN];
int convertT(int h, int m, int s)
{
    return (h * 60 + m) * 60 + s;
}
bool cmp(customer &a, customer &b)
{
    return a.T < b.T;
}
int main()
{
    int K, N;
    scanf("%d%d", &N, &K);
    fill(window, window + K, open_T);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int h, m, s, p;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        int t = convertT(h, m, s);
        if (t <= close_T)
        {
            customers[count].T = t;
            customers[count].P = p * 60;
            count++;
        }
    }
    sort(customers, customers + count, cmp);
    int pos = 0, wait_T = 0;
    while (pos < count)
    {
        sort(window, window + K);
        if (customers[pos].T <= window[0])
        {
            wait_T += window[0] - customers[pos].T;
            window[0] += customers[pos].P;
        }
        else
        {
            window[0] = customers[pos].T + customers[pos].P;
        }
        pos++;
    }
    printf("%.1f\n", wait_T * 1.0 / 60 / count);
    system("pause");
    return 0;
}