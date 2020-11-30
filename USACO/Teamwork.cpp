/*
idea:dp[i]=maximum answer for the elements from i->n 
assuming that the last team ends at cow i
for every i we calculate the best from dp[i]=max of
dp[j-1]+(max element from i->j)*(i-j+1)
for every j in range i and i-k

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 ll n,k,c;
ll a[100000];
ll dp[100000];
ll solve(int i){
    if(i>n){return 0;}
    ll &ans=dp[i];
    if(ans!=-1){
        return ans;
    }
  //  ans=solve(i+1)+a[i];
    ll mx=a[i];
    ll counter=1;
    for(int j=i;j<(i+k)&&j<=n;j++){
        mx=max(mx,a[j]);
        ans=max(ans,solve(j+1)+mx*(j-i+1));
        
    }
    
  return ans;
}

int main() {
    freopen("teamwork.in" , "r" , stdin) ;
    freopen("teamwork.out" , "w" , stdout) ;
  cin>>n>>k;
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++){
      cin>>a[i];
  }
 solve(1); cout<<dp[1];
}
