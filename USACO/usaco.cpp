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
 int a[mx];
 int arr[mx*4];
 void update(int node,int left,int right,int value,int pos){
     if(left==right){
         arr[node]+=value;
       
         return;
     }
     int mid=(left+right)/2;
     if(pos>mid){
       
         update(node*2+1,mid+1,right,value,pos);
       
     }else{
            update(node*2,left,mid,value,pos);
     }
    
     arr[node]=arr[node*2]+arr[node*2+1];
     return;
 }
 int query(int node,int left,int right,int l,int r){
     if(left>r||right<l){
         return 0;
     }
     if(left>=l&&right<=r){
         return arr[node];
     }
     int mid=(left+right)/2;
     return query(node*2,left,mid,l,r)+query(node*2+1,mid+1,right,l,r);
 }
int main(){
    freopen("sleepy.in","r",stdin);
	freopen("sleepy.out","w",stdout);
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
     
      
    int j=n-1;
    while(j>0&&a[j]>a[j-1]){
        j--;
    }// 1 2 3 4756
      for(int i=n-1;i>=j;i--){
      update(1,0,n,1,a[i]);
        
    }cout<<j<<endl;
    for(int i=0;i<j;i++){
      int x=query(1,0,n,0,a[i]);cout<<(j-(i+1))+x;
      if(i<j-1){cout<<" ";}
      update(1,0,n,1,a[i]);
    
    }cout<<endl;
    
   
  
}