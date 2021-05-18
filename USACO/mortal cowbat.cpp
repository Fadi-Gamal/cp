/*
same idea :http://www.usaco.org/current/data/sol_cowmbat_gold_dec19.html
*/
#include<bits/stdc++.h>
using namespace std;
const int mx=100006;
typedef long long ll;
int inf=1e9+10;
const int mod=1e9+7;
ll n,m,k;
int a[mx];
int cost[28][28];
int psum[mx][28];
int mn[mx];
int dp[mx][29];
int main(){

    freopen("cowmbat.in" , "r" , stdin) ;
    freopen("cowmbat.out" , "w" , stdout) ;

 cin>>n>>m>>k;
 string s;cin>>s;
 for(int i=1;i<=n;i++){

    a[i]=s[i-1]-'a';

  }
   for(int i=0;i<m;i++){

    for(int j=0;j<m;j++){

        cin>>cost[i][j];
    }
   }
   for(int k=0;k<m;k++){
     for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){

            cost[i][j]=min(cost[i][k]+cost[k][j],cost[i][j]);
        }


     }

    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            psum[i][j]=cost[a[i]][j];
            if(i){
               psum[i][j]+=psum[i-1][j];
            }
        }
    }
 memset(dp, 0x3f, sizeof dp);
    memset(mn, 0x3f, sizeof mn);
    mn[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){


                    dp[i][j]=dp[i-1][j]+cost[a[i]][j];

            if(i>=k){
                dp[i][j]=min(dp[i][j],psum[i][j]-psum[i-k][j]+mn[i-k]);
                     mn[i]=min(mn[i],dp[i][j]);
            }


        }
        //cout<<mn[i]<<" ";
     }
     cout<<mn[n];

 }
