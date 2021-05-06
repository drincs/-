#include <iostream>
using namespace std;
struct gsk
{
    int g;
    int s;
    int k;
};
gsk add(gsk a, gsk b)
{
    a.k += b.k;
    if (a.k >= 29)
        a.s += a.k / 29;
    a.k = a.k % 29;
    a.s += b.s;
    if (a.s >= 17)
        a.g += a.s / 17;
    a.s = a.s % 17;
    a.g += b.g;
    return a;
}
int main()
{
    gsk a, b;
    scanf("%d.%d.%d", &a.g, &a.s, &a.k);
    scanf("%d.%d.%d", &b.g, &b.s, &b.k);
    a = add(a, b);
    printf("%d.%d.%d\n", a.g, a.s, a.k);
    system("pause");
    return 0;
}