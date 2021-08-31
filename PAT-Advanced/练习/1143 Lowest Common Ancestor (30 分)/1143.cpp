#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
struct node
{
    node *lchild = NULL;
    node *rchild = NULL;
    int key;
    node(int key)
    {
        this->key = key;
    }
};
unordered_map<int, int> nums;
node *root = NULL;
void insert(node *root, int key)
{
    if (root == NULL)
    {
        root = new node(key);
    }
    else
    {
        if (root->key > key)
        {
            insert(root->lchild, key);
        }
        else
        {
            insert(root->rchild, key);
        }
    }
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        int key;
        scanf("%d", &key);
        insert(root, key);
        nums.insert(make_pair(key, 1));
    }
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (nums.count(u) == 0 || nums.count(v) == 0)
        {
            if (nums.count(u) == 0 && nums.count(v) == 0)
            {
                printf("ERROR: %d and %d are not found.\n", u, v);
            }
            else if (nums.count(u) == 0)
            {
                printf("ERROR: %d is not found.\n", u);
            }else{
                printf("ERROR: %d is not found.\n", v);
            }
        }else{
            
        }
    }
    system("pause");
    return 0;
}