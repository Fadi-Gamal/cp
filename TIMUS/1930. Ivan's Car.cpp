*/
by :fadi gamal
link:https://acm.timus.ru/problem.aspx?space=1&num=1930

idea is to use dikjstra from the start node and the cost we keep track of out direction 
every time we change direction costs 1 if dont need to change it its cost nothing
so in the priorty queue we keep track of {cost{node,direction}};
complexity O(ELogV))




*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 ll n,m,c,s,e;
 const int mx=1000000;
vector<pair<int,int>>v[100000];
ll d[mx];
ll vis[1000000];

void dikj(){
    
    priority_queue<pair<int,pair<int,int>>>q;
  q.push({0,{s,1}});  q.push({0,{s,-1}});
  d[s]=0;
  while(q.size()){
      pair<int,pair<int,int>>me=q.top();
      q.pop();
      int node=me.second.first;
      int dir=me.second.second;
      int distt=me.first*-1;
      vis[node]=1;
      
      for(auto i:v[node]){
          if(!vis[i.first]&&(distt+((i.second)!=dir))<d[i.first]){
              
              d[i.first]=distt+((i.second)!=dir);
              q.push({-1*d[i.first],{i.first,i.second}});
          }
      }
  }
    
    
    
}
int main() {
   /* freopen("mooyomooyo.in" , "r" , stdin) ;
    freopen("mooyomooyo.out" , "w" , stdout) ;*/
    
  cin>>n>>m;int x,y;
  for(int i=1;i<=m;i++){
      
      cin>>x>>y;
      v[x].push_back({y,1});
      v[y].push_back({x,-1});
      
      d[x]=10000000;
      d[y]=10000000;
      
  }cin>>s>>e;
 
  
  dikj();
  /* for(auto i:v[2]){
          cout<<i.first<<" "<<i.second<<" ";
      }*/
  cout<<d[e];
  
  
 

}