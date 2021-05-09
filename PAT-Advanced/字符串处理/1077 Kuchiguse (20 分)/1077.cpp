#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n;
    string str;
    cin >> n;
    vector<string> spokens;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        spokens.push_back(str);
    }
    string res = spokens[0];
    for (int i = 1; i < n && res.size() > 0; i++)
    {
        int pos = res.size() - 1;
        int size = spokens[i].size();
        for (int j = size - 1; j >= 0 && pos >= 0; j--, pos--)
        {
            if (spokens[i][j] == res[pos])
            {
                continue;
            }
            else
            {
                res.erase(res.begin(), res.begin() + pos + 1);
                break;
            }
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] != ' ')
        {
            break;
        }
        else
        {
            res.erase(res.begin());
        }
    }
    if (res.size() > 0)
    {
        cout << res << endl;
    }
    else
    {
        cout << "nai" << endl;
    }
    system("pause");
    return 0;
}