#include <iostream>
#include <vector>
using namespace std;
struct node
{
    node *left = NULL;
    node *right = NULL;
    int key;
    node(int val)
    {
        this->key = val;
    }
};
vector<int> pre, post, preMirror, postMirror;

void insert(node *&root, int val, int type)
{
    if (root == NULL)
    {
        root = new node(val);
        return;
    }
    if (val < root->key)
    {
        if (type == 0)
        {
            insert(root->left, val, type);
        }
        else
        {
            insert(root->right, val, type);
        }
    }
    else
    {
        if (type == 0)
        {
            insert(root->right, val, type);
        }
        else
        {
            insert(root->left, val, type);
        }
    }
}
node *Create(vector<int> data, int n, int type)
{
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        insert(root, data[i], type);
    }
    return root;
}
void preOrder(node *root, vector<int> &vi)
{
    if (root == NULL)
    {
        return;
    }
    vi.push_back(root->key);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}
void postOrder(node *root, vector<int> &vi)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->key);
}
bool judge(vector<int> a, vector<int> b)
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
    vector<int> data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        data.push_back(x);
    }
    node *root = Create(data, n, 0);
    node *mirror = Create(data, n, 1);
    preOrder(root, pre);
    preOrder(mirror, preMirror);
    postOrder(root, post);
    postOrder(mirror, postMirror);
    if (judge(pre, data))
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", post[i]);
        }
        printf("\n");
    }
    else if (judge(preMirror, data))
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", postMirror[i]);
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