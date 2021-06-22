#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
struct node
{
    int data;
    node *lchild;
    node *rchild;
};
int pre[31], in[31];
int n;
node *create(int preL, int preR, int inL, int inR)
{
    if (preL > preR)
    {
        return NULL;
    }
    node *root = new node();
    root->data = pre[preL];
    int k = inL;
    for (k; k <= inR; k++)
    {
        if (in[k] == pre[preL])
        {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}
int num = 0;
void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d", root->data);
    num++;
    if (num < n)
        printf(" ");
}
int main()
{
    scanf("%d", &n);
    int preIndex = 0, inIndex = 0;
    stack<int> st;
    for (int i = 0; i < 2 * n; i++)
    {
        char op[4];
        scanf("%s", op);
        if (op[1] == 'o')
        {
            //中序
            in[inIndex++] = st.top();
            st.pop();
        }
        else
        {
            //先序
            scanf("%d", &pre[preIndex++]);
            st.push(pre[preIndex - 1]);
        }
    }
    node *root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    printf("\n");
    system("pause");
    return 0;
}