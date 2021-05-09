/*
USACO Timeline
solution:toposort


*/
#include<bits/stdc++.h>
using namespace std;
const int mx=15;
typedef long long ll;
int inf=1e9+10;
const int mod=1e9+7;
int n,m,c;
 int visited[100001];
 vector<pair<int,int>>adj[100001];
vector<int>topo;
 void dfs(int node){

 visited[node]=1;

 for(auto it:adj[node]){

    if(!visited[it.first]){
        dfs(it.first);
    }
 }
 topo.push_back(node);



 }

int s[100001];
int main(){
    freopen("timeline.in" , "r" , stdin) ;
    freopen("timeline.out" , "w" , stdout) ;
cin>>n>>m>>c;
int ans[n+2];
for(int i=1;i<=n;i++){

    cin>>s[i];
    ans[i]=s[i];
 }

int dp[n+2];
memset(dp,0,sizeof(dp));
vector<int>backedge[mx];
for(int i=0;i<c;i++){

int a,b,x;
cin>>a>>b>>x;
    adj[a].push_back({b,x});
   // backedge[b].push_back(a);
}
for(int i=1;i<=n;i++){
    if(!visited[i]){
            dfs(i);
    }
}

reverse(topo.begin(),topo.end());
dp[1]=1;
for(int i=0;i<topo.size();i++){

    for(auto it:adj[topo[i]]){
        ans[it.first]= max(ans[it.first],ans[topo[i]]+it.second);
    }

 }
for(int i=1;i<=n;i++){cout<<ans[i]<<"\n";}
}
