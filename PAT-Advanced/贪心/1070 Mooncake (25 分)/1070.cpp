#include <iostream>
#include <algorithm>
using namespace std;
struct cake
{
    double num;
    double price;
    double per;
};
bool cmp(cake &a, cake &b)
{
    return a.per > b.per;
}
int main()
{
    int n, d;
    cake cakes[1001];
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cakes[i].num);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cakes[i].price);
        cakes[i].per = cakes[i].price / cakes[i].num;
    }
    sort(cakes, cakes + n, cmp);
    double profit = 0;
    for (int i = 0; i < n && d > 0; i++)
    {
        if (d >= cakes[i].num)
        {
            profit += cakes[i].price;
            d -= cakes[i].num;
        }
        else
        {
            profit += d * cakes[i].per;
            d = 0;
        }
    }
    printf("%.2f\n", profit);
    system("pause");
    return 0;
}