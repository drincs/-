#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct school{
    string id;
    double tws=0;
    int ns=0;
    int rank;
    school(string id){
        this->id=id;
    }
};
vector<school> all;
unordered_map<string,int> getId;
bool cmp(school &a,school &b){
    if(a.tws==b.tws){
        if(a.ns==b.ns){
            return a.id<b.id;
        }
        return a.ns<b.ns;
    }
    return a.tws>b.tws;
}
int main(){
    int n;
    int count=0;
    for(int i=0;i<n;i++){
        string sid,id;
        int score;
        cin>>sid>>score>>id;
        id=tolower(id);
        if(getId.count(id)==0){
            getId.insert(make_pair(id,count));
            all.push_back(school(id));
            count++;
        }
        int iid=getId[id];
        if(sid[0]=='A'){
            all[iid].tws+=score;
        }else if(sid[0]=='B'){
            all[iid].tws+=score*1.0/1.5;
        }else{
            all[iid].tws+=score*1.5;
        }
        all[iid].ns++;
    }
    sort(all.begin(),all.end(),cmp);
    int rank=1;
    double now=all[0].tws;
    count<<count<<endl;
    for(int i=0;i<count;){
        int j=i;
        while(now==all[j].tws){
            cout<<rank<<" "<<all[j].id<<" "<<all[i].tws<<" "<<all[i].ns<<endl;  
            j++;
        }
        now=all[j].tws;
        i=j;
    }
    system("pause");
    return 0;

}