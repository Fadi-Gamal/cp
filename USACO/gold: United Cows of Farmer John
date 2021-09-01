#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
const int mx=2e5+5;
typedef long long ll;
 int mod=1e9+7;
const int MXm=22;
#define F first
#define S second
const int inf=1e9+10;


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n;
int a[mx];
int prv[mx];
ll seg[4*mx];
  ll query(int node,int l,int r,int left,int right){

    if(l>=left&&r<=right){
    
        return seg[node];
    }
    if(r<left||l>right){

        return 0;
    }

    int mid=(l+r)/2;
   return query(node*2,l,mid,left,right) + query(node*2+1,mid+1,r,left,right);
  }
  void update(int node,int l,int r,int idx,int val){
   //cout<<l<<" "<<r<<" "<<endl;
    if(l==r){


        seg[node]=val;
        return;
    }
    int mid=(l+r)/2;

  if(idx>mid){

    update(node*2+1,mid+1,r,idx,val);
  }else{

   update(node*2,l,mid,idx,val);

   }
   seg[node]=seg[node*2]+seg[node*2+1];
  return;
}
  int main(){
     /*
   freopen("perechi3.in" , "r" , stdin) ;
    freopen("perechi3.out" , "w" , stdout) ;
    */
     cin>>n;

ll ans=0;
/*

7
1 2 3 4 3 2 5
*/
/*
   update(1,1,n,1,1);
 cout<<query(1,1,n,1,1);
*/
    for(int i=1;i<=n;i++){

    cin>>a[i];
    int me=a[i];

      ans+=query(1,0,n,prv[me]+1,i-1);
      if(prv[me]!=0){


        update(1,0,n,prv[me],0);

      }

 update(1,0,n,i,1);
 //cout<<query(1,0,n,1,1);
      prv[me]=i;
    }


  cout<<ans;
    }
