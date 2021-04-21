#include <iostream>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        long long A, B, C;
        bool res = false;
        scanf("%lld%lld%lld", &A, &B, &C);
        // 考虑溢出情况
        long long temp = A + B;
        if (A > 0 && B > 0 && temp < 0)
        {
            //正溢出
            res = true;
        }
        else if (A < 0 && B < 0 && A + B >= 0)
        {
            //负溢出
            res = false;
        }
        else
        {
            res = A + B > C ? true : false;
        }
        if (res)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    system("pause");
    return 0;
}