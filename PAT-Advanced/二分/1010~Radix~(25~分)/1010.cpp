#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
long long ctoNum(char a)
{
    if (a >= '0' && a <= '9')
    {
        return a - '0';
    }
    else if (a >= 'a' && a <= 'z')
    {
        return a - 'a' + 10;
    }
}
long long toTen(char n[], int radix)
{
    long long t = 0;
    long long len = strlen(n);
    for (long long i = len - 1; i >= 0; i--)
    {
        long long pos = ctoNum(n[i]);
        t += pow(radix, len - 1 - i) * pos;
    }
    return t;
}
long long getMin(char n[])
{
    long long res = -1;
    long long len = strlen(n);
    for (long long i = 0; i < len; i++)
    {
        if (ctoNum(n[i]) > res)
        {
            res = ctoNum(n[i]);
        }
    }
    return res + 1;
}
long long cmp(char n[], long long radix, long long t)
{
    long long a = toTen(n, radix);
    if (a < 0)
        return 1;
    if (a > t)
        return 1;
    else if (a == t)
        return 0;
    else
        return -1;
}
long long bs(char n[], long long l, long long r, long long t)
{
    long long mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        long long flag = cmp(n, mid, t);
        if (flag == 0)
            return mid;
        else if (flag == 1)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    long long tag, radix, res;
    char n1[11], n2[11];
    scanf("%s%s%d%d", n1, n2, &tag, &radix);
    long long num1;
    if (tag == 2)
    {
        char tmp[11];
        strcpy(tmp, n1);
        strcpy(n1, n2);
        strcpy(n2, tmp);
    }
    num1 = toTen(n1, radix);
    //统一计算n2的进制数
    long long l = getMin(n2);
    //从max+1开始
    long long r = (l > num1 ? l : num1) + 1;
    long long ans = bs(n2, l, r, num1);
    if (ans == -1)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}