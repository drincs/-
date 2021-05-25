#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n, d;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 0)
            break;
        scanf("%d", &d);
        bool res = false;
        if (isPrime(n))
        {
            //本身素数
            int rn = 0;
            while (n > 0)
            {
                rn = rn * d + n % d;
                n /= d;
            }
            if (isPrime(rn))
            {
                res = true;
            }
        }
        if (res)
            printf("Yes\n");
        else
            printf("No\n");
    }
    system("pause");
    return 0;
}