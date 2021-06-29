#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
    int data = -1;
    int left = -1;
    int right = -1;
};
node tree[1001];
int cnt = 0;
int pos = 0;
int n;
vector<int> inorder;
void in(int idx)
{
    if (idx == -1)
    {
        return;
    }
    in(tree[idx].left);
    tree[idx].data = inorder[pos++];
    in(tree[idx].right);
}
void level(int root)
{
    if (root == -1)
    {
        return;
    }
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        if (cnt != 0)
            printf(" ");
        cnt++;
        printf("%d", tree[top].data);
        if (tree[top].left != -1)
        {
            q.push(tree[top].left);
        }
        if (tree[top].right != -1)
        {
            q.push(tree[top].right);
        }
    }
    printf("\n");
}
int main()
{
    scanf("%d", &n);
    //输入为先序遍历
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &tree[i].left, &tree[i].right);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        inorder.push_back(x);
    }
    sort(inorder.begin(), inorder.end());
    in(0);
    level(0);
    system("pause");
    return 0;
}