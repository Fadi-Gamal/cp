/*
same idea as the editerial
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx=1e5+5;
const int mod= 1e9+7 ;
const ll inf=1;



//***while there is life there is hope
 int n,m,q;
 int par[mx];
 int siz[mx];

void init(){
for(int i=1;i<=n;i++){
    siz[i]=1;
    par[i]=i;
}



}
int root(int x){

if(par[x]!=x){
    return par[x]=root(par[x]);
}
return x;


}
void unit(int x,int y){

int a=root(x);
int b=root(y);
if(a==b){return;}

if(siz[a]>siz[b]){swap(a,b);}
par[a]=b;
siz[b]+=siz[a];

}

vector<pair<int,pair<int,int>>>edges;
vector<pair<int,pair<int,int>>>queires;
int main() {
freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
 cin>>n>>q;
init();
 for(int i=0;i<n-1;i++){
        int x,y,z;
    cin>>x>>y>>z;
    edges.push_back({z,{x,y}});
 }
 sort(edges.begin( ),edges.end());
 for(int i=0;i<q;i++){

    int k,x;
    cin>>k>>x;
    queires.push_back({k,{x,i}});
 }
 sort(queires.begin(),queires.end());
 reverse(queires.begin(),queires.end());
 reverse(edges.begin( ),edges.end());
 int p=0;
 int ans[q+2];
 /*for(int i=0;i<=n;i++){
    cout<<par[i]<<" ";
 }*/
 //cout<<endl;
 for(int i=0;i<q;i++){
        int ww=queires[i].first;
    while(p<n-1&&edges[p].first>=ww){
        unit(edges[p].second.first,edges[p].second.second);
        p++;
    }
    int xx=queires[i].second.first;
    int idx=queires[i].second.second;
   // cout<<ww<<" "<<xx<<" "<<idx<<" "<<p<<endl;
    ans[idx]=siz[root(xx)];
    //cout<<"test "<<par[xx]<<endl;

 }


for(int i=0;i<q;i++){
    cout<<ans[i]-1<<endl;
}












}








