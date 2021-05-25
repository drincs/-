#include <iostream>
using namespace std;
typedef long long ll;
struct fenshu
{
    ll sign = 1;
    ll up = 0;
    ll down = 1;
};
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
    ll g = gcd(a.up, a.down);
    a.up = a.up / g;
    a.down = a.down / g;
    if (a.up == 0)
    {
        a.sign = 1;
        a.down = 1;
    }
    return a;
}
fenshu add(fenshu a, fenshu b)
{
    fenshu res;
    res.up = a.sign * a.up * b.down + b.sign * b.up * a.down;
    res.down = a.down * b.down;
    if (res.up < 0)
    {
        res.up *= -1;
        res.sign *= -1;
    }
    res = yuefen(res);
    return res;
}
fenshu diff(fenshu a, fenshu b)
{
    fenshu res;
    res.up = a.sign * a.up * b.down - b.sign * b.up * a.down;
    res.down = a.down * b.down;
    if (res.up < 0)
    {
        res.up *= -1;
        res.sign *= -1;
    }
    res = yuefen(res);
    return res;
}
fenshu product(fenshu a, fenshu b)
{
    fenshu res;
    res.sign = a.sign * b.sign;
    res.up = a.up * b.up;
    res.down = a.down * b.down;
    if (res.up < 0)
    {
        res.up *= -1;
        res.sign *= -1;
    }
    res = yuefen(res);
    return res;
}
fenshu quot(fenshu a, fenshu b)
{
    fenshu res;
    res.sign = a.sign * b.sign;
    res.up = a.up * b.down;
    res.down = a.down * b.up;
    if (res.up < 0)
    {
        res.up *= -1;
        res.sign *= -1;
    }
    if (res.up != 0)
        res = yuefen(res);
    return res;
}
fenshu dealSign(fenshu a)
{
    if (a.up < 0)
    {
        a.sign *= -1;
        a.up *= -1;
    }
    if (a.down < 0)
    {
        a.sign *= -1;
        a.down *= -1;
    }
    return a;
}
void show(fenshu a)
{
    if (a.sign < 0)
        printf("(-");
    //带分数的输出
    if (a.down == 1)
        printf("%lld", a.up);
    else
    {
        if (a.up > a.down)
            printf("%lld %lld/%lld", a.up / a.down, a.up % a.down, a.down);
        else
            printf("%lld/%lld", a.up % a.down, a.down);
    }
    if (a.sign < 0)
        printf(")");
}
int main()
{
    fenshu a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    a = dealSign(a);
    b = dealSign(b);
    a = yuefen(a);
    b = yuefen(b);
    fenshu res[4];
    res[0] = add(a, b);
    res[1] = diff(a, b);
    res[2] = product(a, b);
    res[3] = quot(a, b);
    char op[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++)
    {
        show(a);
        printf(" %c ", op[i]);
        show(b);
        printf(" = ");
        if (i == 3)
        {
            if (b.up == 0)
                printf("Inf");
            else
                show(res[i]);
        }
        else
        {
            show(res[i]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}