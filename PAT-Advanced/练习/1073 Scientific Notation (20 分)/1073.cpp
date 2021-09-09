#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    char a[10000];
    scanf("%s", a);
    int e = 0;
    bool sign = a[0] == '+' ? true : false;
    int i = 1;
    vector<int> zhengshu;
    vector<int> xiaoshu;
    while (a[i] != '.')
    {
        zhengshu.push_back(a[i] - '0');
        i++;
    }
    i++;
    while (a[i] != 'E')
    {
        xiaoshu.push_back(a[i] - '0');
        i++;
    }
    i++;
    bool esign = a[i] == '+' ? true : false;
    i++;
    while (a[i] != '\0')
    {
        e = e * 10 + (a[i] - '0');
        i++;
    }
    if (esign)
    {
        //小数挪整数
        while (e--)
        {
            if (xiaoshu.size() > 0)
            {
                zhengshu.push_back(xiaoshu[0]);
                xiaoshu.erase(xiaoshu.begin());
            }
            else
            {
                zhengshu.push_back(0);
            }
        }
    }
    else
    {
        while (e--)
        {
            if (zhengshu.size() > 0)
            {
                xiaoshu.insert(xiaoshu.begin(), *(zhengshu.end() - 1));
                zhengshu.erase(zhengshu.end() - 1);
            }
            else
            {
                xiaoshu.insert(xiaoshu.begin(), 0);
            }
        }
    }
    if (!sign)
        printf("-");
    if (zhengshu.size() == 0)
        printf("0");
    for (int i = 0; i < zhengshu.size(); i++)
    {
        printf("%d", zhengshu[i]);
    }
    if (xiaoshu.size() > 0)
        printf(".");
    for (int i = 0; i < xiaoshu.size(); i++)
    {
        printf("%d", xiaoshu[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
