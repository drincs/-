#include <iostream>
#include <string>
using namespace std;
int n;
string deal(string a, int &e)
{
    int i = 0;
    //移除前导0
    while (a[0] == '0' && a.size() > 0)
    {
        a.erase(a.begin());
    }
    if (a[0] == '.')
    {
        //小数
        a.erase(a.begin());
        while (a[0] == '0' && a.size() > 0)
        {
            a.erase(a.begin());
            e--;
        }
    }
    else
    {
        //大于等于1
        while (i < a.size() && a[i] != '.')
        {
            i++;
            e++;
        }
        if (i < a.size())
        {
            a.erase(a.begin() + i);
        }
    }
    if (a.size() == 0)
    {
        e = 0;
    }
    i = 0;
    string res;
    while (i < n && i < a.size())
    {
        res += a[i];
        i++;
    }
    while (i < n)
    {
        res += '0';
        i++;
    }
    return res;
}
int main()
{
    string a, b;
    cin >> n >> a >> b;
    int e1 = 0, e2 = 0;
    string s1 = deal(a, e1);
    string s2 = deal(b, e2);
    if (s1.compare(s2) == 0)
    {
        cout << "YES 0." << s1 << "*10^" << e1 << endl;
    }
    else
    {

        cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2 << endl;
    }
    system("pause");
    return 0;
}