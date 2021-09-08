#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    char a[10000];
    scanf("%s", &a);
    vector<int> zhengshu;
    vector<int> xiaoshu;
    int e = 0;
    int l = strlen(a);
    int sign = a[0] == '+' ? 0 : 1;
    int i = 1;
    while (a[i] != '.')
    {
        zhengshu.push_back(a[i++] - '0');
    }
    i++;
    while (a[i] != 'E')
    {
        xiaoshu.push_back(a[i++] - '0');
    }
    i++;
    int esign = a[i++] == '+' ? 0 : 1;
    while (i < l)
    {
        e = e * 10 + (a[i++] - '0');
    }
    while (e--)
    {
        if (esign == 0)
        {
            //小数挪到整数
            if (xiaoshu.size() > 0)
            {
                zhengshu.push_back(*xiaoshu.begin());
                xiaoshu.erase(xiaoshu.begin());
            }
            else
            {
                zhengshu.push_back(0);
            }
        }
        else
        {
            //整数挪到小数
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
    if (sign == 1)
        printf("-");
    if (zhengshu.size() == 0)
    {
        printf("0");
    }
    else
    {
        for (int i = 0; i < zhengshu.size(); i++)
        {
            printf("%d", zhengshu[i]);
        }
    }
    if(xiaoshu.size()!=0)printf(".");
    for (int i = 0; i < xiaoshu.size(); i++)
    {
        printf("%d", xiaoshu[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
