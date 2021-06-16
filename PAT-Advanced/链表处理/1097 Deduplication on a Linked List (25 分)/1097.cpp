#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 10001;
int main()
{
    bool isExist[MAXN] = {false};
    int key[MAXN * 10], next[MAXN * 10], list[MAXN * 10], remain[MAXN * 10];
    int head, n;
    scanf("%d%d", &head, &n);
    for (int i = 0; i < n; i++)
    {
        int addr, val, nt;
        scanf("%d%d%d", &addr, &val, &nt);
        key[addr] = val;
        next[addr] = nt;
    }
    int ptr = head, ct1 = 0, ct2 = 0;
    while (ptr != -1)
    {
        int k = abs(key[ptr]);
        if (isExist[k] == false)
        {
            list[ct1++] = ptr;
            isExist[k] = true;
        }
        else
        {
            remain[ct2++] = ptr;
        }
        ptr = next[ptr];
    }
    if (ct1 > 0)
    {
        for (int i = 0; i < ct1 - 1; i++)
        {
            printf("%05d %d %05d\n", list[i], key[list[i]], list[i + 1]);
        }

        printf("%05d %d -1\n", list[ct1 - 1], key[list[ct1 - 1]]);
    }
    if (ct2 > 0)
    {
        for (int i = 0; i < ct2 - 1; i++)
        {
            printf("%05d %d %05d\n", remain[i], key[remain[i]], remain[i + 1]);
        }

        printf("%05d %d -1\n", remain[ct2 - 1], key[remain[ct2 - 1]]);
    }
    system("pause");
    return 0;
}