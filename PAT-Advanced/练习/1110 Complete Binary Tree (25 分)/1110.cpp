#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<bool> findRoot(n, true);
    vector<bool> hasValue(n + 1, false);
    vector<vector<int>> relation(n, vector<int>(2, -1));
    vector<int> tree(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        char s1[3], s2[3];
        scanf("%s%s", s1, s2);
        int a = 0, b = 0;
        if (s1[0] != '-')
        {
            int j = 0;
            while (s1[j] != '\0')
            {
                a = a * 10 + (s1[j++] - '0');
            }
            relation[i][0] = a;
            findRoot[a] = false;
        }
        if (s2[0] != '-')
        {
            int j = 0;
            while (s2[j] != '\0')
            {
                b = b * 10 + (s2[j++] - '0');
            }
            relation[i][1] = b;
            findRoot[b] = false;
        }
    }
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        if (findRoot[i])
        {
            root = i;
            break;
        }
    }
    int i = 1;
    tree[i] = root;
    hasValue[i] = true;
    bool isComp = true;
    while (i <= n / 2)
    {
        int pos = tree[i];
        if (pos < 0)
        {
            isComp = false;
            break;
        }
        if (relation[pos][0] >= 0)
        {
            if (hasValue[i * 2] == true)
            {
                isComp = false;
                break;
            }
            tree[i * 2] = relation[pos][0];
            hasValue[i * 2] = true;
        }
        else
        {
            if (i * 2 <= n)
            {
                isComp = false;
                break;
            }
        }

        if (relation[pos][1] >= 0)
        {
            if (hasValue[i * 2 + 1] == true)
            {
                isComp = false;
                break;
            }
            tree[i * 2 + 1] = relation[pos][1];
            hasValue[i * 2 + 1] = true;
        }
        else
        {
            if (i * 2 + 1 <= n)
            {
                isComp = false;
                break;
            }
        }
        i++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!hasValue[i])
        {
            isComp = false;
            break;
        }
    }
    if (isComp)
    {
        printf("YES %d\n", tree[n]);
    }
    else
    {
        printf("NO %d\n", tree[1]);
    }
    system("pause");
    return 0;
}