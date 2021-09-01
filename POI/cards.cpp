#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
const int mx=2e5+20;
typedef long long ll;
int mod=1e9+7;
const int MXm=22;
#define ff first
#define ss second
const ll inf=1e9+10;
int n,m;
pair<ll,ll>a[mx],seg[4*mx];
void merg(int node,int l,int r){
  seg[node]={inf,inf};
    int mid=(l+r)/2;
   //using the first card of the segment
  if(seg[node*2].ff<=a[mid+1].second){
    seg[node].ff=seg[node*2+1].ss;

    }
if(seg[node*2].ff<=a[mid+1].ff){
    seg[node].ff=seg[node*2+1].ff;

    }

//using the second card of the segment

   if(seg[node*2].ss<=a[mid+1].second){
    seg[node].ss=seg[node*2+1].ss;

    }
if(seg[node*2].ss<=a[mid+1].ff){
    seg[node].ss=seg[node*2+1].ff;

    }


return;


}
void build(int node,int l,int r){
   seg[node]={inf,inf};

   if(l==r){
 seg[node]=a[l];
    return;
   }
  int mid=(l+r)/2;
  build(node*2,l,mid);
  build(node*2+1,mid+1,r);
  merg(node,l,r);
  }
  void update(int node,int l,int r,int idx){


   if(l==r){

    seg[node]=a[l];
    return;
   }
   int mid=(l+r)/2;
   if(idx<=mid){
     update(node*2,l,mid,idx);
   }else{
    update(node*2+1,mid+1,r,idx);

   }

  merg(node,l,r);

  return;



  }

 int main(){
     cin>>n;

     for(int i=0;i<n;i++){

        cin>>a[i].ff>>a[i].ss;
        if(a[i].ss<a[i].ff){

        swap(a[i].ff,a[i].ss);

        }
     }

     build(1,0,n-1);
   int m;
   cin>>m;
   for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y; 
    x--;y--;
    swap(a[x],a[y]);
    update(1,0,n-1,x);
    update(1,0,n-1,y);
      if (seg[1].ff == inf)
        cout << "NIE\n";
    else
        cout << "TAK\n";

   }
  // cout<<seg[1].ff<<" "<<seg[1].ss;
  }
