// 堆以树形结构存储，如果P是C的父结点，那么P的键值大于等于C的键值在大堆里，小于等于C的键值在小堆里。
// 二叉堆 二叉树 从根节点到叶结点 一定是大到小或者小到大的序列。
// 检查是否是一个堆
// 输入: N[1,1000]
// N个不同的整数键值（二叉树的中序遍历）
// 输出:输出根结点到叶结点 右子树优先
// 输出最大堆 还是 最小堆 还是 不是堆
#include <iostream>
#include <vector>
using namespace std;
int tree[10001];
int n;
int type = -2;
void dfs(int now, vector<int> path)
{
    if (now < n)
    {
        if (type == -2)
        {
            if (tree[now] < tree[(now - 1) / 2])
            {
                type = 0;
            }
            else if (tree[now] > tree[(now - 1) / 2])
            {
                type = 1;
            }
        }
        else
        {
            if (type == 0 && tree[now] > tree[(now - 1) / 2])
            {
                type = -1;
            }
            else if (type == 1 && tree[now] < tree[(now - 1) / 2])
            {
                type = -1;
            }
        }
        path.push_back(tree[now]);
        if (now * 2 + 1 < n)
        {
            dfs(now * 2 + 2, path);
            dfs(now * 2 + 1, path);
        }
        else
        {
            //不存在子结点
            vector<int>::iterator it = path.begin();
            for (it; it != path.end(); it++)
            {
                if (it != path.begin())
                    printf(" ");
                printf("%d", *it);
            }
            printf("\n");
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
    }
    vector<int> a;
    dfs(0, a);
    if (type == -1)
    {
        printf("Not Heap\n");
    }
    else if (type == 0)
    {
        printf("Max Heap\n");
    }
    else
    {
        printf("Min Heap\n");
    }
    system("pause");
    return 0;
}