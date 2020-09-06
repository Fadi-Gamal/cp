/* Author : fadi gamal (handle : fadi57MohamedAhmed04)
   contest name USACO 2019 December Contest, Silver
   problem name :Milk Visits
   problem link : http://usaco.org/index.php?page=viewproblem2&cpid=968
   problem solution :
   	same idea : 
   	https:http://usaco.org/current/data/sol_milkvisits_silver_dec19.html
*/



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;string s;
const int mx=1e5+9;
ll comp[mx];
int visited[mx];
vector<int>v[mx];
char cc[mx];
ll num=1;
void dfs(int ii){
    if(visited[ii]){return;}
    visited[ii]=1;
    for(auto i:v[ii]){
        if(s[ii-1]==s[i-1]){
            comp[i]=num;
            dfs(i);
        }else{
             //comp[i]=comp[ii]+1;
            
        }
    }
}
int main() {
     freopen("milkvisits.in" , "r" , stdin) ;
    freopen("milkvisits.out" , "w" , stdout) ;
 cin>>n>>m>>s;
 for(int i=0;i<n-1;i++){
     int x,y;cin>>x>>y;
    v[x].push_back(y); 
    v[y].push_back(x);
 }
 //dfs(1);
  for(int i=1;i<=n;i++){
      if(comp[i]==0){
      comp[i]=num;
   dfs(i);num++;}
    
 }
 
 //cout<<comp[1]<<comp[3];
 //return 0;
  for(int i=0;i<m;i++){
     int x,y;char t;
     //cout<<9;
     cin>>x>>y>>t;
    
     if(comp[x]==comp[y]){
         if(s[x-1]==t){cout<<'1';}else{cout<<0;}
     }else{
             cout<<1;
         }
    
 }
  
}