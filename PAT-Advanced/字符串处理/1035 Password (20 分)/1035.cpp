#include <iostream>
#include <vector>
using namespace std;
struct account
{
    char name[11];
    char pwd[11];
};
int main()
{
    int n;
    scanf("%d", &n);
    vector<account> res;
    for (int i = 0; i < n; i++)
    {
        account temp;
        scanf("%s %s", temp.name, temp.pwd);
        bool flag = false;
        for (int j = 0; temp.pwd[j] != '\0'; j++)
        {
            if (temp.pwd[j] == '1')
            {
                flag = true;
                temp.pwd[j] = '@';
            }
            else if (temp.pwd[j] == '0')
            {
                flag = true;
                temp.pwd[j] = '%';
            }
            else if (temp.pwd[j] == 'l')
            {
                flag = true;
                temp.pwd[j] = 'L';
            }
            else if (temp.pwd[j] == 'O')
            {
                flag = true;
                temp.pwd[j] = 'o';
            }
        }
        if (flag)
            res.push_back(temp);
    }
    if (res.size() > 0)
    {
        printf("%d\n", res.size());
        for (int i = 0; i < res.size(); i++)
        {
            printf("%s %s\n", res[i].name, res[i].pwd);
        }
    }
    else
    {
        if (n > 1)
            printf("There are %d accounts and no account is modified\n", n);
        else
        {
            printf("There is 1 account and no account is modified\n");
        }
    }
    system("pause");
    return 0;
}