#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    string speech;
    getline(cin, speech);
    map<string, int> dict;
    map<string, int>::iterator it;
    string word;
    for (int i = 0; i <= speech.length(); i++)
    {
        if (speech[i] >= '0' && speech[i] <= '9')
        {
            word += speech[i];
        }
        else if (speech[i] >= 'a' && speech[i] <= 'z')
        {
            word += speech[i];
        }
        else if (speech[i] >= 'A' && speech[i] <= 'Z')
        {
            word += (speech[i] - 'A' + 'a');
        }
        else
        {
            if (word != "")
            {
                it = dict.find(word);
                if (it != dict.end())
                {
                    it->second++;
                }
                else
                {
                    dict.insert(make_pair(word, 1));
                }
                word = "";
            }
            else
            {
                continue;
            }
        }
    }

    int time = 0;
    string res;
    for (it = dict.begin(); it != dict.end(); it++)
    {
        if (it->second > time)
        {
            time = it->second;
            res = it->first;
        }
    }
    cout << res << " " << time << endl;
    system("pause");
    return 0;
}