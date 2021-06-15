#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; i++)
    {
        int seq[1001];
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &seq[j]);
        }
        //模拟
        stack<int> tmp;
        int pos = 1;
        int el = 1;
        while (pos <= N)
        {
            if (tmp.empty())
            {
                tmp.push(el++);
            }
            while (tmp.size() < M && tmp.top() != seq[pos])
            {
                //非空栈且栈顶非当前需弹出元素
                tmp.push(el++);
            }
            while (tmp.size() > 0 && tmp.top() == seq[pos])
            {
                tmp.pop();
                pos++;
            }
            if (tmp.size() == M)
            {
                printf("NO\n");
                break;
            }
        }
        if (pos > N)
            printf("YES\n");
    }
    system("pause");
    return 0;
}