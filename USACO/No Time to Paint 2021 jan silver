#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx=1e5+5;
const int mod= 1e9+7 ;
const int inf=1e7;
int n,m,k;

//***while there is life there is hope
int pref[mx];int suf[mx];
int main() {

int t;t=1;
while(t--){

map<int,int>mp;
map<int,int>mp2;
int n,q;cin>>n>>q;
string s;cin>>s;
 for(int i=0;i<n;i++){

    if(mp[s[i]-'A']==0){
        pref[i]++;
    }
    int z='Z'-'A';
    int me=s[i]-'A';
    me++;
    for(int j=me;j<=z;j++){
        mp[j]=0;
    }me--;
    mp[me]++;
    if(i){
    pref[i]+=pref[i-1];}
   // cout<<pref[i]<<" ";
  }
  for(int i=n-1;i>=0;i--){
    if(mp2[s[i]-'A']==0){
        suf[i]++;
    } int z='Z'-'A';
    int me=s[i]-'A';
    me++;
    for(int j=me;j<=z;j++){
        mp2[j]=0;
    }me--;
    mp2[me]++;
    suf[i]+=suf[i+1];
//cout<<suf[i]<<" ";
  }
  for(int i=0;i<q;i++){


    int l,r;cin>>l>>r;
    l--;r--;
    int ans=0;
    if(l>0){ ans+=pref[l-1];}
    if(r<n-1){ans+=suf[r+1];}
   cout<<ans<<endl;
  }

    //cout<<ans<<endl;



}

  }















