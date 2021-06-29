#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
vector<int> level;
vector<int> inorder;
int idx = 0;
void in(int root)
{
    if (root > n)
    {
        return;
    }
    //设置左子树
    in(root * 2);
    level[root] = inorder[idx++];
    //设置右子树
    in(root * 2 + 1);
}
int main()
{
    scanf("%d", &n);
    //计算层数k
    k = (int)(ceil(log2(n + 1)));
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        inorder.push_back(x);
    }
    level.assign(n + 1, -1);
    sort(inorder.begin(), inorder.end());
    in(1);
    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", level[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}