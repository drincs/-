#include<iostream>
#include <vector>
using namespace std;

vector<int> tree;
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
        int key;
        scanf("%d",&key);
        tree.push_back(key);
    }
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
    }
    system("pause");
    return 0;
}