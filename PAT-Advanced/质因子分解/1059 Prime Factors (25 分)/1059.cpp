#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n)
{
    if (n == 1)
        return false;
    int sqr = (int)sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int prime[100010], num = 0;
void Find_Prime()
{
    for (int i = 1; i < 100010; i++)
    {
        if (isPrime(i))
        {
            prime[num++] = i;
        }
    }
}
struct fac
{
    int x;
    int s = 0;
};
int main()
{
    int n;
    Find_Prime();
    fac res[100];
    int idx = 0;
    scanf("%d", &n);
    if (n == 1)
        printf("1=1\n");
    else
    {
        printf("%d=", n);
        int sqr = (int)sqrt(n * 1.0);
        for (int i = 0; i < num && prime[i] <= sqr; i++)
        {
            if (n % prime[i] == 0)
            {
                res[idx].x = prime[i];
                while (n % prime[i] == 0)
                {
                    res[idx].s++;
                    n /= prime[i];
                }
                idx++;
            }
            if (n == 1)
            {
                break;
            }
        }
        if (n != 1)
        {
            res[idx].x = n;
            res[idx].s = 1;
            idx++;
        }
        for (int i = 0; i < idx; i++)
        {
            if (i != 0)
                printf("*");
            printf("%d", res[i].x);
            if (res[i].s > 1)
                printf("^%d", res[i].s);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}