#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
int n;
int judgeMax(int i)
{
    if (i * 2 <= n)
        if (tree[i] < tree[i * 2])
        {
            return -1;
        }
        else
        {
            int res = judgeMax(i * 2);
            if (res == -1)
            {
                return -1;
            }
        }
    if (i * 2 + 1 <= n)
        if (tree[i] < tree[i * 2 + 1])
        {
            return -1;
        }
        else
        {
            int res = judgeMax(i * 2 + 1);
            if (res == -1)
            {
                return -1;
            }
        }
    return 1;
}
int judgeMin(int i)
{
    if (i * 2 <= n)
        if (tree[i] > tree[i * 2])
        {
            return -1;
        }
        else
        {
            int res = judgeMin(i * 2);
            if (res == -1)
            {
                return -1;
            }
        }
    if (i * 2 + 1 <= n)
        if (tree[i] > tree[i * 2 + 1])
        {
            return -1;
        }
        else
        {
            int res = judgeMin(i * 2 + 1);
            if (res == -1)
            {
                return -1;
            }
        }
    return 1;
}
void postOrder(int i)
{
    if (i * 2 <= n)
    {
        postOrder(i * 2);
    }
    if (i * 2 + 1 <= n)
    {
        postOrder(i * 2 + 1);
    }
    printf("%d", tree[i]);
    if (i != 1)
    {
        printf(" ");
    }
}
int main()
{
    int m;
    scanf("%d%d", &m, &n);
    tree.assign(n + 1, 0);
    while (m--)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &tree[i]);
        }
        int j1 = judgeMax(1);
        if (j1 == 1)
            printf("Max Heap\n");
        else
        {
            int j2 = judgeMin(1);
            if (j2 == 1)
                printf("Min Heap\n");
            else
            {
                printf("Not Heap\n");
            }
        }
        postOrder(1);
        printf("\n");
    }
    system("pause");
    return 0;
}