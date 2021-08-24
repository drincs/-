#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int d, n;
    scanf("%d%d", &d, &n);
    n--;
    vector<char> ans;
    ans.push_back(d + '0');
    while (n--)
    {
        vector<char> temp;
        for (int i = 0; i < ans.size();)
        {
            int j = 1;
            while (i + j < ans.size())
            {
                if (ans[i] == ans[i + j])
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            temp.push_back(ans[i]);
            temp.push_back(j + '0');
            i += j;
        }
        ans.clear();
        ans.assign(temp.begin(), temp.end());
    }
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%c", ans[i]);
    }
    cout << endl;
    system("pause");
    return 0;
}