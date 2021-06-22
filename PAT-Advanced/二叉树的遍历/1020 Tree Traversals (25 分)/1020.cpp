#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
struct node
{
    int val = 0;
    node *lchild;
    node *rchild;
};
int post[31];
int in[31];
int N;
node *create(int postL, int postR, int inL, int inR)
{
    if (postL > postR)
    {
        return NULL;
    }
    node *nroot = new node;
    nroot->val = post[postR];
    //根结点在in中查找
    int k = inL;
    for (k; k <= inR; k++)
    {
        if (in[k] == post[postR])
        {
            break;
        }
    }
    int numLeft = k - inL;
    nroot->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    nroot->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return nroot;
}
int num = 0;
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *top = q.front();
        q.pop();
        printf("%d", top->val);
        num++;
        if (num < N)
            printf(" ");
        if (top->lchild != NULL)
            q.push(top->lchild);
        if (top->rchild != NULL)
            q.push(top->rchild);
    }
}
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &post[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &in[i]);
    }
    node *root = create(1, N, 1, N);
    bfs(root);
    printf("\n");
    system("pause");
    return 0;
}