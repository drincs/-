#include <iostream>
using namespace std;
int main()
{
    int K;
    int twice = 2;
    double c[1001]={0};
    while (twice--)
    {
        scanf("%d", &K);
        for (int i = 0; i < K; i++)
        {
            int n;
            double a;
            scanf("%d %lf",&n,&a);
            c[n]+=a;
        }
    }
    int num=0;
    for(int i=0;i<1001;i++){
        if(c[i]!=0.0){
            num++;
        }
    }
    printf("%d",num);
    for(int i=1000;i>=0;i--){
        if(c[i]!=0.0){
            printf(" %d %.1f",i,c[i]);
        }
    }
    printf("\n");
    system("pause");
    return 0;
}