#include <iostream>
#include <vector>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
    node(int val)
    {
        this->data = val;
        this->right = NULL;
        this->left = NULL;
    }
};
vector<int> origin, pre, post, preMirror;
node *mirror = NULL;

void insert(node *&root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        return;
    }
    if (root->data > val)
    {
        insert(root->left, val);
    }
    else
    {
        insert(root->right, val);
    }
}
void reverse_insert(node *&root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        return;
    }
    if (root->data > val)
    {
        reverse_insert(root->right, val);
    }
    else
    {
        reverse_insert(root->left, val);
    }
}
node *create(vector<int> &data, int n)
{
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
        reverse_insert(mirror, data[i]);
    }
    return root;
}
void preOrder(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    preOrder(root->left, v);
    preOrder(root->right, v);
}
void postOrder(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left, v);
    postOrder(root->right, v);
    v.push_back(root->data);
}
bool judge(vector<int> &a, vector<int> &b)
{
    bool res = true;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            res = false;
            break;
        }
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        origin.push_back(x);
    }
    node *bst = create(origin, n);
    preOrder(bst, pre);
    preOrder(mirror, preMirror);
    if (judge(origin, pre))
    {

        postOrder(bst, post);
        printf("YES\n");
        for (int i = 0; i < post.size(); i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", post[i]);
        }
        printf("\n");
    }
    else if (judge(origin, preMirror))
    {
        postOrder(mirror, post);
        printf("YES\n");
        for (int i = 0; i < post.size(); i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", post[i]);
        }
        printf("\n");
    }
    else
    {
        printf("NO\n");
    }
    system("pause");
    return 0;
}