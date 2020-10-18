/*
USACO 2020 US Open Contest, Gold
Problem 1. Haircut
let y[i] be the number of pairs (x,i) where a[x]>a[i]&&x<i
for each j the answer is the of sum y[i] for all is where a[i]<j 
we calculate it with prefix sum


*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef long long ll;
const int mx=1e5+20;
const int inf=1e9;
const int mod=998244353 ;
int ans[mx];
ll suminv[mx];
int main(){
    freopen("haircut.in","r",stdin);
	freopen("haircut.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
indexed_set s;
vector<int>v[mx];
int n;cin>>n;int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
    v[a[i]].push_back(i);
}for(int i=n;i>=0;i--){
    for(auto j:v[i]){
        suminv[i+1]+=s.order_of_key(j);
    }
    for(auto j:v[i]){
       s.insert(j);
    }
}
for(int i=1;i<n;i++){
   if(i==0){continue;}else{
       suminv[i]+=suminv[i-1];
       
   }
}for(int i=0;i<n;i++){
  cout<<suminv[i]<<endl;
}
}