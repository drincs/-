#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int f = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        if (t - f > 0)
        {
            ans += 6 * (t - f) + 5;
        }
        else
        {
            ans += 4 * (f - t) + 5;
        }
        f = t;
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}