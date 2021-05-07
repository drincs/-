//1061 Dating
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//string a b c d
// a b第一个相同的大写字母代表周几
// a b第二个相同的字母代表 时
// cd第一个相同字母的位置代表 分
int getDay(char c)
{
    return c - 'A';
}
int getHour(char c)
{
    if ('0' <= c && c <= '9')
    {
        return c - '0';
    }
    return c - 'A' + 10;
}
string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int capital = 0;
    int letter = 0;
    int day, hour, min;
    day = hour = min = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            if (a[i] >= 'A' && a[i] <= 'G')
            {
                capital++;
                letter++;
            }
            else if ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'A' && a[i] <= 'N'))
            {
                if (capital > 0)
                    letter++;
            }
            else
            {
                continue;
            }
            if (capital == 1 && letter == 1)
            {
                day = getDay(a[i]);
            }
            if (letter == 2)
            {
                hour = getHour(a[i]);
            }
        }
        if (letter == 2 && capital == 1)
        {
            break;
        }
    }
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] == d[i] && ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')))
        {
            min = i;
            break;
        }
    }
    cout << week[day] << " " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << endl;
    return 0;
}