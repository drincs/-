#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string &a, string &b)
{
    return a + b < b + a;
}
int main()
{
    int n;
    vector<string> segments;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        segments.push_back(tmp);
    }
    sort(segments.begin(), segments.end(), cmp);
    string res = "";
    for (int i = 0; i < n; i++)
    {
        res += segments[i];
    }
    while (res.size() > 0 && res[0] == '0')
    {
        res.erase(res.begin());
    }
    if (res.size() == 0)
        cout << 0 << endl;
    else
        cout << res << endl;
    system("pause");
    return 0;
}