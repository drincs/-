#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
struct node
{
    int id;
    int height = 1;
    int lchild = -1;
    int rchild = -1;
} nodes[10];
bool isChild[10] = {false};
int n;
int num = 0;
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        printf("%d", nodes[top].id);
        num++;
        if (num < n)
            printf(" ");
        if (nodes[top].lchild != -1)
        {
            q.push(nodes[top].lchild);
        }
        if (nodes[top].rchild != -1)
        {
            q.push(nodes[top].rchild);
        }
    }
}
void inorder(int root)
{
    //左中右
    if (root == -1)
    {
        return;
    }
    inorder(nodes[root].lchild);
    printf("%d", nodes[root].id);
    num++;
    if (num < 2 * n)
        printf(" ");
    inorder(nodes[root].rchild);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        nodes[i].id = i;
        char l, r;
        getchar();
        scanf("%c %c", &l, &r);
        if (l >= '0' && l <= '9')
        {
            nodes[i].rchild = l - '0';
            isChild[l - '0'] = true;
        }
        if (r >= '0' && r <= '9')
        {
            nodes[i].lchild = r - '0';
            isChild[r - '0'] = true;
        }
    }
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (isChild[i] == false)
        {
            root = i;
            break;
        }
    }
    //反转输出层序中序
    bfs(root);
    printf("\n");
    inorder(root);
    printf("\n");
    system("pause");
    return 0;
}