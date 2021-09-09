#include <iostream>
#include <string>
#include <vector>
using namespace std;
double sum = 0;
int n, num = 0;

bool legal(string a)
{
    int sign = 1;
    int i = 0;
    if (a[0] == '+' || a[0] == '-' || (a[0] >= '0' && a[0] <= '9'))
    {
        if (a[0] == '-')
        {
            sign = -1;
            i = 1;
        }
        else if (a[0] == '+')
        {
            i = 1;
        }
    }
    else
    {
        return false;
    }
    //整数部分校验
    int zhengshu = 0;
    while (a[i] != '\0' && a[i] != '.')
    {
        if (!(a[i] >= '0' && a[i] <= '9'))
            return false;
        zhengshu = zhengshu * 10 + a[i++] - '0';
        if (zhengshu > 1000)
            return false;
    }
    vector<int> xiaoshu;
    if (a[i] == '.')
    {
        i++;
        while (a[i] != '\0')
        {
            if (a[i] == '.')
                return false;
            if (!(a[i] >= '0' && a[i] <= '9'))
                return false;
            xiaoshu.push_back(a[i++] - '0');
        }
        while (xiaoshu.size() > 0 && *(xiaoshu.end() - 1) == 0)
        {
            xiaoshu.erase(xiaoshu.end() - 1);
        }
        if (xiaoshu.size() > 2)
            return false;
        if (zhengshu == 1000 && xiaoshu.size() > 0)
            return false;
    }
    sum = sum + sign * zhengshu * 1.0;
    double d = 0.1;
    for (int i = 0; i < xiaoshu.size(); i++)
    {
        sum += sign * xiaoshu[i] * d;
        d *= 0.1;
    }
    num++;
    return true;
}
int main()
{
    scanf("%d", &n);
    string s;
    getchar();
    while (n--)
    {
        cin >> s;
        if (!legal(s))
        {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        }
    }
    if (num > 1)
        printf("The average of %d numbers is %.2f\n", num, sum / num);
    else if (num == 1)

        printf("The average of 1 number is %.2f\n", sum);
    else
        printf("The average of 0 numbers is Undefined\n");

    system("pause");
    return 0;
}