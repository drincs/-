#include <iostream>
#include <math.h>
using namespace std;
const int MAXN=10001;
int dp[MAXN],A[MAXN];
int wanted[201];
int color_rank[201];
int main(){
    int n,m,l;
    scanf("%d%d",&n,&m);
    fill(color_rank,color_rank+n,0);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        color_rank[x]=i;
    }
    scanf("%d",&l);
    int num=0;
    for(int i=0;i<l;i++){
        int x;
        scanf("%d",&x);
        if(color_rank[x]>0){
            A[num++]=color_rank[x];
        }
    }
    int ans=-1;
    for(int i=0;i<num;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]>A[j]&&(dp[j]+1)>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}