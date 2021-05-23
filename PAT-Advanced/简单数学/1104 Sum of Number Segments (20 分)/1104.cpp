#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    long double res = 0;
    for (int i = 0; i < n; i++)
    {
        double t;
        scanf("%lf", &t);
        res += t * (i + 1) * (n - i);
    }
    printf("%.2Lf\n", res);
    system("pause");
    return 0;
}