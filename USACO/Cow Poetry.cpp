/*
idea same as the editerial




*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 ll n,m,k;
 const int mx=1000000;

const int MOD=1000000007;
ll s[mx],c[mx];
ll dp[mx];//n of ways to have a line of x syllables
ll r[mx];// r[i]the number of ways to have a line with k syllables ending with a syllable of rythme i
char rh[mx];
map<char,int>mp;
map<char,int>f;
//fast exponentiation
long long exp(int base, ll power){
   if(power == 0) return 1;
   if(power == 1) return (base + MOD) % MOD;
   long long ans = exp(base,power/2);
   ans = (ans * ans + MOD) % MOD;
   if(power%2 == 1) ans = (ans*base + MOD) % MOD;
   return (ans + MOD) % MOD;
}
int main() {
    freopen("poetry.in" , "r" , stdin) ;
    freopen("poetry.out" , "w" , stdout) ;
    //n words m lines k syllables
  cin>>n>>m>>k;
  
  dp[0]=1;
  
for(int i=0;i<n;i++){
    cin>>s[i]>>c[i];
    }
    
   
    for(int j=1;j<=k;j++){
         for(int i=0;i<n;i++){
        if(j-s[i]>=0){
            dp[j]=(dp[j]+dp[j-s[i]]+MOD)%MOD;
            if(j==k){r[c[i]]=(r[c[i]]+dp[j-s[i]]+MOD)%MOD;}
        }
    }
    }
for(int i=0;i<m;i++){
    cin>>rh[i];
    f[rh[i]]++;
}


ll ans=1;
for(auto i:f){
     //if(mp[i]){continue;}
    //mp[rh[i]]=1;
    ll subanswer=0;
    for(int j=1;j<=n;j++){
        if(r[j]==0){
            continue;
        }else{subanswer=(subanswer+exp(r[j],i.second)+MOD)%MOD;}
    }ans=(ans*subanswer+MOD)%MOD;
    
}
 
cout<<ans;
}