#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx=5005;
const int mod= 1e9+7 ;
const ll inf=1e9;



//***while there is life there is hope
int n,m,k,q;
int seg[mx*4];
int a[mx];
int upd(int node,int l,int r,int x,int val){






}
int dp[102][102][102];
int solve(int i,int j,int last){
int &ret=dp[i][j][last];
if(ret!=-1){return ret;}
if(i==n-1){
     if(j==0){
        return (a[i]!=last);
     }else{return inf;}
  //  if(j==0){return 0;}else{return inf;}
}
 ret=1e9;
if(j){

    ret=solve(i+1,j-1,0)+(a[i]!=last);
}
ret=min(solve(i+1,j,last+1)+(a[i]!=last),ret);
//cout<<ret<<endl;
return ret;





 }



int main() {
 freopen(" taming.in" , "r" , stdin) ;
    freopen(" taming.out" , "w" , stdout) ;
int t;t=1;

cin>>n;

for(int i=0;i<n;i++){cin>>a[i];}
memset(dp,-1,sizeof(dp));

for(int i=0;i<n;i++){
        cout<<solve(0,i,0);
 cout<<endl;
}


}








