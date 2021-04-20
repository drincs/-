#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main()
{
    int k;
    char shape[6] = "SHCDJ";
    vector<int> cards;
    vector<int> res;
    vector<int> order;
    scanf("%d", &k);
    for (int i = 1; i <= 54; i++)
    {
        cards.push_back(i);
        res.push_back(0);
        int temp;
        scanf("%d", &temp);
        order.push_back(temp - 1);
    }
    while (k--)
    {
        for (int i = 0; i < 54; i++)
        {
            int pos = order[i];
            res[pos] = cards[i];
        }
        cards = res;
    }
    printf("%c%d", shape[(res[0] - 1) / 13], (res[0] - 1) % 13 + 1);
    for (int i = 1; i < 54; i++)
    {
        printf(" %c%d", shape[(res[i] - 1) / 13], (res[i] - 1) % 13 + 1);
    }
    printf("\n");
    system("pause");
    return 0;
}