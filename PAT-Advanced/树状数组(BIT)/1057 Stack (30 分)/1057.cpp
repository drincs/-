#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
#define lowbit(i) ((i) & (-i))
const int MAXN = 100010;
int hashNum[MAXN];
stack<int> st;
void push(int x, int v)
{
    st.push(x);
    for (int i = x; i < MAXN; i += lowbit(i))
    {
        hashNum[i] += v;
    }
}
void pop(int x, int v)
{
    printf("%d\n", x);
    st.pop();
    for (int i = x; i < MAXN; i += lowbit(i))
    {
        hashNum[i] -= v;
    }
}
int getSum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += hashNum[i];
    }
    return sum;
}
void peek(int k)
{
    int l = 1, r = MAXN, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (getSum(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}
int main()
{
    int n;
    scanf("%d", &n);
    fill(hashNum, hashNum + MAXN, 0);
    for (int i = 0; i < n; i++)
    {
        char cmd[20];
        scanf("%s", cmd);
        if (cmd[1] == 'u')
        {
            int key;
            scanf("%d", &key);
            push(key, 1);
        }
        else if (cmd[1] == 'o')
        {
            if (st.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                int key = st.top();
                pop(key, 1);
            }
        }
        else
        {

            if (st.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                peek((st.size() + 1) / 2);
            }
        }
    }
    system("pause");
    return 0;
}