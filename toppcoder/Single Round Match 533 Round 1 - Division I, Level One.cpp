/*
idea:dp[l][r] is the maximum anser to  make the elements in range l and r disaper
first we pich and number l<i<l so that its the last  element to disaper in this range 
ex: 1,2,3,4   l=1 r=n if we chose 3 to be the last element then we have to solve for 3,4 and 123 separtly and add a[l]*a[r]





*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx=1e5+9;
const ll mod=1e9+7;
ll n,l,k;
ll w[mx],x[mx],d[mx];
ll sum;
long long ncr[2005][2005];
ll a[mx];
ll dp[60][60];
ll solve(int l,int r){
    if(r-l<2){return 0;}
    if(r-l==2){
        return a[l]*a[r];
    }
    ll &ret=dp[l][r];
    if(ret!=-1){return ret;}
   for(int i=l+1;i<r;i++){ 
       ret=max(ret,solve(l,i)+solve(i,r)+a[l]*a[r]);
   }
   return ret;
    
}
int main() {
   // cout<<1ll*(1<<30);
  cin>>n;
memset(dp,-1,sizeof(dp));

for(int i=1;i<=n;i++){
  
 cin>>a[i];
   
  
}
cout<<solve(1,n);
}
