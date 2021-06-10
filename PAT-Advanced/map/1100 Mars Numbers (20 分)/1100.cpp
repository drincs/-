#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
string gw[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string sw[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, string> dict;
void init()
{
    for (int i = 0; i < 169; i++)
    {

        string word = "";
        if (i / 13 > 0)
        {
            word = sw[i / 13];
            if (i % 13 > 0)
                word += " " + gw[i % 13];
        }
        else
        {
            word = gw[i % 13];
        }
        int t = i;
        string cur = "";
        do
        {
            cur += t % 10 + '0';
            t /= 10;
        } while (t > 0);
        reverse(cur.begin(), cur.end());
        dict.insert(make_pair(word, cur));
        dict.insert(make_pair(cur, word));
    }
}
int main()
{
    init();
    int n;
    cin >> n;
    char a[8];
    cin.getline(a, 8);
    while (n--)
    {
        cin.getline(a, 8);
        if (dict.count(a) > 0)
        {
            cout << (dict[a]) << endl;
        }
    }
    system("pause");
    return 0;
}