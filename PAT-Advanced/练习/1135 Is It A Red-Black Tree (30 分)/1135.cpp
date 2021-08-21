#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct node
{
    int v, height, sign = 1;
    node *lchid = NULL, *rchild = NULL;
};
node *newNode(int v)
{
    node *Node = new node;
    Node->v = abs(v);
    Node->sign = v > 0 ? 1 : -1;
    Node->height = 1;
    Node->lchid = Node->rchild = NULL;
    return Node;
}
int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
int getBlanceFactor(node *root)
{
    if (root == NULL)
        return 0;
    return getHeight(root->lchid) - getHeight(root->rchild);
}
void updateHeight(node *root)
{
    if (root == NULL)
    {
        return;
    }
    root->height = max(getHeight(root->lchid), getHeight(root->rchild)) + 1;
}
void L(node *&root)
{
    node *temp = root->rchild;
    root->rchild = temp->lchid;
    temp->lchid = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void R(node *&root)
{
    node *temp = root->lchid;
    root->lchid = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
node *insert(node *&root, int v)
{
    if (root == NULL)
    {
        root = newNode(v);
    }
    else if (abs(v) <= root->v)
    {
        root->lchid = insert(root->lchid, v);
    }
    else
    {
        root->rchild = insert(root->rchild, v);
    }
    return root;
}
node *Create(vector<int> data)
{
    node *root = NULL;
    for (int i = 0; i < data.size(); i++)
    {
        root = insert(root, data[i]);
    }
    return root;
}
//根结点是黑
bool judge1(node *root)
{
    if (root != NULL && root->sign == -1)
    {
        return false;
    }
    return true;
}
//如果一个结点是红，所有孩子结点是黑。
bool judge2(node *root)
{
    if (root == NULL)
        return true;
    if (root->sign < 0)
    {
        if (root->lchid != NULL && root->lchid->sign < 0)
            return false;
        if (root->rchild != NULL && root->rchild->sign < 0)
            return false;
    }
    return judge2(root->lchid) && judge2(root->rchild);
}
int getNum(node *root)
{
    if (root == NULL)
        return 0;
    int l = getNum(root->lchid);
    int r = getNum(root->rchild);
    return root->sign > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge3(node *root)
{
    if (root == NULL)
        return true;
    int l = getNum(root->lchid);
    int r = getNum(root->rchild);
    if (l != r)
        return false;
    return judge3(root->lchid) && judge3(root->rchild);
}
int main()
{
    int k;
    scanf("%d", &k);
    while (k--)
    {
        int n;
        scanf("%d", &n);
        vector<int> data;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            data.push_back(x);
        }
        node *root = Create(data);
        if (judge1(root) && judge2(root) && judge3(root))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    system("pause");
    return 0;
}