#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll; //中间乘积可能会超出2^31
int main()
{
    int n;
    scanf("%d", &n);
    int sqr = (int)sqrt(n * 1.0);
    int i = 2;
    int len = 0;
    int res = 0;
    for (i; i <= sqr; i++)
    {
        int t = i;
        ll p = i;
        while (p <= n && n % p == 0)
        {
            t++;
            p *= t;
        }
        if (t - i > len)
        {
            len = t - i;
            res = i;
        }
    }
    printf("%d\n", len > 0 ? len : 1);
    if (len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (i != 0)
                printf("*");
            printf("%d", res + i);
        }
    }
    else
    {
        printf("%d", n);
    }
    printf("\n");

    system("pause");
    return 0;
}