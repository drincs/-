#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int M, N;
    map<int, int> colors;
    scanf("%d%d", &M, &N);
    int total = M * N;
    map<int, int>::iterator it;
    while (N--)
    {
        for (int i = 0; i < M; i++)
        {
            int t;
            scanf("%d", &t);
            it = colors.find(t);
            if (it != colors.end())
            {
                it->second++;
            }
            else
            {

                colors.insert(make_pair(t, 1));
            }
        }
    }
    for (it = colors.begin(); it != colors.end(); it++)
    {
        if (it->second * 2 > total)
        {
            printf("%d\n", it->first);
            break;
        }
    }
    system("pause");
    return 0;
}