#include <iostream>
#include <math.h>
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
using namespace std;
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    while (isPrime(m) == false)
    {
        m++;
    }
    bool hash[11111] = {0};
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        int pos = num % m;
        if (i != 0)
            printf(" ");
        if (!hash[pos])
        {
            hash[pos] = true;
            printf("%d", pos);
        }
        else
        {
            //Quadratic probing
            bool find = false;
            for (int j = 1; j < m; j++)
            {
                int qb = (num + j * j) % m;
                if (!hash[qb])
                {

                    hash[qb] = true;
                    printf("%d", qb);
                    find = true;
                    break;
                }
            }
            if (!find)
            {
                printf("-");
            }
        }
    }
    printf("\n");
    system("pause");
    return 0;
}