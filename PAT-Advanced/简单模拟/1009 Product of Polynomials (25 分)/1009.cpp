#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct poly
{
    int exp;
    double coe;
    poly(int exp, double coe)
    {
        this->exp = exp;
        this->coe = coe;
    }
};
bool cmp(poly &a, poly &b)
{
    return a.exp > b.exp;
}
int main()
{
    int K;
    vector<poly> A, B;
    vector<double> C;
    //input
    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        int n;
        double a;
        scanf("%d%lf", &n, &a);
        A.push_back(poly(n, a));
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        int n;
        double a;
        scanf("%d%lf", &n, &a);
        B.push_back(poly(n, a));
    }
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    int maxn = A.begin()->exp + B.begin()->exp;
    C.assign(maxn + 1, 0);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            C[A[i].exp + B[j].exp] += A[i].coe * B[j].coe;
        }
    }
    vector<poly> res;
    for (int i = maxn; i >= 0; i--)
    {
        if (C[i] != 0.0)
        {
            res.push_back(poly(i, C[i]));
        }
    }
    printf("%d", res.size());
    for (int i = 0; i < res.size(); i++)
    {
        printf(" %d %.1f", res[i].exp, res[i].coe);
    }
    printf("\n");
    system("pause");
    return 0;
}