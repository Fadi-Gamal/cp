#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
 
const int mx=200006;
const int mod= 998244353;
const ll inf=1e8;
// bool[9][9];
 
int dp[9][9][(1<<9)][(1<<3)][2];
int arr[9][9];
int solve(int x,int y,int mask1,int mask2,int me){
    
    
//int ret=dp[x][y][mask1][mask2][me];
    if(x==9){
        if(mask1==0){return 0;}
        return inf;
    }
    
    if(y==9){
        if((x+1)%3==0&&mask2){return inf;}
        if(me){return inf;}
        if((x)%3==2){
            mask2=0;
        }return solve(x+1,0,mask1,mask2,0);
        
       
    }int &ret=dp[x][y][mask1][mask2][me];
    if(ret!=-1){return ret;}ret=inf;
    int choice1= (arr[x][y]==0)+solve(x,y+1,mask1^(1<<y),mask2^(1<<(y/3)),me^1);
    int choice2=(arr[x][y]==1)+ solve(x,y+1,mask1,mask2,me);
    ret=min(choice1,choice2);return ret;
}

int main() {
    freopen("bsudoku.in" , "r" , stdin) ;
    freopen("bsudoku.out" , "w" , stdout) ;
    memset(dp , -1 , sizeof(dp));
for(int i=0;i<9;i++){
    string s;
    cin>>s;
    for(int j=0;j<9;j++){
        arr[i][j]=s[j]-'0';
    }
}

cout<<solve(0,0,0,0,0);
}