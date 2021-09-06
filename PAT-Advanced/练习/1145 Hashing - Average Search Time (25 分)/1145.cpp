#include <iostream>
#include <vector>
using namespace std;
bool isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int s, n, m;
    scanf("%d%d%d", &s, &n, &m);
    while (!isprime(s))
    {
        s++;
    }
    vector<int> v(s, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        bool flag = false;
        for (int k = 0; k < s; k++)
        {
            int p = k * k;
            int hk = (x + p) % s;
            if (v[hk] == 0)
            {
                v[hk] = x;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            //cannot.push_back(x)
            printf("%d cannot be inserted.\n", x);
        }
    }
    int total = 0;
    for (int i = 0; i < m; i++)
    {
        int q;
        scanf("%d", &q);
        for (int k = 0; k <= s; k++)
        {
            total++;
            int p = k * k;
            int hk = (q + p) % s;
            if (v[hk] == q || v[hk] == 0)
            {
                break;
            }
        }
    }
    printf("%.1lf\n", total * 1.0 / m);
    system("pause");
    return 0;
}