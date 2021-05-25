#include <iostream>
typedef long long ll;
using namespace std;
struct fenshu
{
    ll fenzi = 0;
    ll fenmu = 1;
    ll sign = 1; //1为正 -1为负
};
//最大公约数
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        gcd(b, a % b);
    }
}
fenshu yuefen(fenshu a)
{
    ll g = gcd(a.fenzi, a.fenmu);
    a.fenzi /= g;
    a.fenmu /= g;
    if (a.fenzi == 0)
    {
        a.fenmu = 1;
        a.sign = 1;
    }
    return a;
}
fenshu add(fenshu a, fenshu b)
{
    fenshu res;
    res.fenzi = a.sign * a.fenzi * b.fenmu + b.sign * b.fenzi * a.fenmu;
    res.fenmu = a.fenmu * b.fenmu;
    if (res.fenzi < 0)
    {
        res.fenzi *= -1;
        res.sign *= -1;
    }
    res = yuefen(res);
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    fenshu res;
    for (int i = 0; i < n; i++)
    {
        fenshu t;
        scanf("%lld/%lld", &t.fenzi, &t.fenmu);
        if (t.fenzi < 0)
        {
            t.fenzi *= -1;
            t.sign *= -1;
        }
        // 根据上一回提交测试点一个都没过的情况我决定加入分母输入为负的可能
        if (t.fenmu < 0)
        {
            t.fenmu *= -1;
            t.sign *= -1;
        }
        res = add(res, t);
    }
    if (res.sign < 0)
        printf("-");
    //带分数的输出
    if (res.fenmu == 1)
        printf("%lld\n", res.fenzi);
    else
    {
        if (res.fenzi > res.fenmu)
            printf("%lld %lld/%lld\n", res.fenzi / res.fenmu, res.fenzi % res.fenmu, res.fenmu);
        else
            printf("%lld/%lld\n", res.fenzi % res.fenmu, res.fenmu);
    }
    system("pause");
    return 0;
}