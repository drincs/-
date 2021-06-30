#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int height = 0;
    int data = 0;
    node *lchild = NULL;
    node *rchild = NULL;
    node(int key)
    {
        this->data = key;
        this->height = 1;
    }
};
int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
void updateHeight(node *root)
{
    if (root == NULL)
    {
        return;
    }
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBalanceFactor(node *root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}
void LeftRotate(node *&root)
{
    node *temp = root->rchild;
    //将右孩子的左孩子给到根结点的右孩子
    root->rchild = temp->lchild;
    // 将根结点成为右孩子的左孩子
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    //右孩子成为根结点
    root = temp;
}
void RightRotate(node *&root)
{
    node *temp = root->lchild;
    //将左孩子的右孩子给到根结点的左孩子
    root->lchild = temp->rchild;
    // 将根结点成为左孩子的右孩子
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    //左孩子成为根结点
    root = temp;
}
void insert(node *&root, int key)
{
    if (root == NULL)
    {
        root = new node(key);
        return;
    }
    if (root->data > key)
    {
        insert(root->lchild, key);
        //完成插入后更新高度
        updateHeight(root);
        //查找失衡点
        if (getBalanceFactor(root) == 2)
        {
            //LL
            int bl = getBalanceFactor(root->lchild);
            if (bl == 1)
            {
                RightRotate(root);
            }
            else if (bl == -1)
            {
                LeftRotate(root->lchild);
                RightRotate(root);
            }
        }
    }
    else
    {

        insert(root->rchild, key);
        //完成插入后更新高度
        updateHeight(root);
        if (getBalanceFactor(root) == -2)
        {
            //RR RL
            int bl = getBalanceFactor(root->rchild);
            if (bl == 1)
            {
                //RL
                RightRotate(root->rchild);
                LeftRotate(root);
            }
            else if (bl == -1)
            {
                //RR
                LeftRotate(root);
            }
        }
    }
}
node *create(int n)
{
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int key;
        scanf("%d", &key);
        insert(root, key);
    }
    return root;
}
int main()
{
    int n;
    scanf("%d", &n);
    node *root = create(n);
    printf("%d\n", root->data);
    system("pause");
    return 0;
}