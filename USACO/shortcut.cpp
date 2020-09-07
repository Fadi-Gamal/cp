/*

solution:first we run dikjstra to calculate the shortest path from node 1 to all others node
while we store the parent of every node so we can travers the path to the barn
and we need to compute the shortest lexorg.. path
w
then we run dfs from node 1 to calculate the number of cows who path by node i in their way to the barn
the last step we try every node to be the node to whom we add the trail and we maximaize the answer






*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 ll n,m,t;
 const int mx=100090;

const int MOD=1000000007;
const int inf=1e9;
//fast exponentiation
int visited[mx];
int visited2[mx];
ll dist[mx];
vector<int>edgee[mx];

vector<pair<ll,ll>>edges[mx];

ll c[mx];
ll summ[mx];
ll nxt[mx];
int visitt[mx];
void dikj(ll s){
    priority_queue<pair<ll,ll>>q;
    dist[s]=0;
    q.push({0,s});
    while(q.size()){
        
        pair<ll,ll>me=q.top();
         q.pop();
        ll node=me.second;
        ll distance=me.first*-1;
       
        for(auto i:edges[node]){
            //relax
            ll node2=i.first;
            if(distance+i.second<dist[i.first]){
              
                 nxt[node2]=node;
                dist[node2]=distance+i.second;
                q.push({dist[node2]*-1,node2});
            }else if(distance+i.second==dist[node2]){
                if(node<nxt[node2]){
                     nxt[node2]=node;
                    // nxt[node]
              
                }
                
                
                
            }
        }
        
    }
    
}
int dfs(int i){
    
    visitt[i]=1;
   int sum=c[i];
    for(auto j:edgee[i]){
        if(visitt[j]){continue;}
       sum+= dfs(j);
    }
    summ[i]=sum;
    return sum;
}
int main() {
  freopen("shortcut.in" , "r" , stdin) ;
    freopen("shortcut.out" , "w" , stdout) ;
  
  
cin>>n>>m>>t;
for(int i=1;i<=n;i++){
    cin>>c[i];
    dist[i]=inf;
}
for(int i=1;i<=m;i++){
    ll x,y,z;
    cin>>x>>y>>z;
   // cout<<x<<" "<<y<<" "<<z<<endl;cout<<"|   |"<<endl;
    edges[x].push_back({y,z});
      edges[y].push_back({x,z});
}

dikj(1);
ll ans=0;
/*
for(int i=1;i<=n;i++){
  cout<<dist[i]<<" ";
}return 0;
debug
*/
for(int i=1;i<=n;i++){
  ans+=(c[i])*dist[i];
}

ll anwser=0;
 

for(int i=2;i<=n;i++){
 //cout<<nxt[i]<<" ";
  edgee[i].push_back(nxt[i]);  
  edgee[nxt[i]].push_back(i);
  
}
dfs(1);//here we calculate summ 
for(int i=1;i<=n;i++){
    ll temp=ans-(dist[i]*summ[i]);
    
    temp+=summ[i]*t;
    anwser=max(ans-temp,anwser);
   
}

//cout<<endl;
cout<<anwser;
}