#include <iostream>
#include <math.h>
#include <map>
#include <iomanip>
using namespace std;
char num[1000];
bool isPrime(int n)
{
    bool res = true;
    if (n == 0 || n == 1)
        return false;
    else if (n == 2)
        return true;
    else
    {
        int sqr = sqrt(n);
        for (int i = 2; i <= sqr; i++)
        {
            if (n % i == 0)
            {
                res = false;
                break;
            }
        }
    }
    return res;
}
int main()
{
    int l, k;
    scanf("%d%d", &l, &k);
    int c = 0;
    getchar();
    for (int i = 0; i < l; i++)
    {
        char temp;
        scanf("%c", &temp);
        if (c == 0 && temp == '0')
        {
            continue;
        }
        else
        {
            num[c++] = temp;
        }
    }
    bool find = false;
    for (int i = 0; i < c - k + 1; i++)
    {
        int tmp = 0;
        for (int j = 0; j < k; j++)
        {
            tmp = tmp * 10 + (num[i + j] - '0');
        }
        if (isPrime(tmp))
        {
            cout << setfill('0') << setw(k) << tmp << endl;
            find = true;
            break;
        }
    }
    if (!find)
        printf("404\n");
    system("pause");
    return 0;
}