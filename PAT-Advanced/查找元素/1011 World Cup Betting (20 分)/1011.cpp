#include <iostream>
using namespace std;
int main()
{
    double odds = 0.65;
    char bet[3] = {'W', 'T', 'L'};
    int best[3];
    for (int i = 0; i < 3; i++)
    {
        double w, t, l;
        scanf("%lf%lf%lf", &w, &t, &l);
        if (w >= t && w >= l)
        {
            best[i] = 0;
            odds *= w;
        }
        else if (t >= w && t >= l)
        {
            best[i] = 1;
            odds *= t;
        }
        else
        {
            best[i] = 2;
            odds *= l;
        }
    }
    double res = (odds - 1) * 2;
    for (int i = 0; i < 3; i++)
    {
        printf("%c ", bet[best[i]]);
    }
    printf("%.2f\n", res);
    system("pause");
    return 0;
}