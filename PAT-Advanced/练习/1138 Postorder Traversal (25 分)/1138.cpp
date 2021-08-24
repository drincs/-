#include <iostream>
using namespace std;
int pre[50001];
int in[50001];
bool flag = false;
void post(int prel, int inl, int inr)
{
    if (inl > inr || flag)
    {
        return;
    }
    int i = inl;
    while (pre[prel] != in[i])
        i++;
    post(prel + 1, inl, i - 1);
    post(prel + i - inl + 1, i + 1, inr);
    if (flag == false)
    {
        printf("%d\n", in[i]);
        flag = true;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }
    post(0, 0, n - 1);
    system("pause");
    return 0;
}