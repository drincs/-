#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN = 10111;
vector<int> num;
vector<bool> visited(MAXN, false);
vector<int> matrix(MAXN, 0);
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int val;
        scanf("%d", &val);
        num.push_back(val);
    }
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    int m = ceil(sqrt(1.0 * N));
    while (N % m != 0)
        m++; //除不整的时候m++
    int n = N / m;
    int i = 0, j = 0;

    int level = 0;
    int pos = 0;
    while (!visited[i * n + j])
    {
        if (pos < N)
        {
            matrix[i * n + j] = num[pos++];
        }
        else
        {
            break;
        }
        visited[i * n + j] = true;
        if (i == level && j < n - 1 - level)
        {
            j++;
        }
        else if (j == n - 1 - level && i < m - 1 - level)
        {
            i++;
        }
        else if (i == m - 1 - level && j > level)
        {
            j--;
        }
        else if (j == level && i > level + 1)
        {
            i--;
            if (i == level + 1)
                level++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0)
                printf(" ");
            if (matrix[i * n + j] == 0)
                printf(" ");
            else
                printf("%d", matrix[i * n + j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}