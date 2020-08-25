/* Author : fadi gamal (handle : fadi57MohamedAhmed04)
   contest name : Baltic olympiad in informatics 2011
   problem name : Treasures and Vikings
   problem link : https://cses.fi/100/list/
   problem solution :
   	same idea : 
   	https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/Baltic/official/boi2011_solutions/vikings-sol.pdf
*/


#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long

const int mx=800;
char a[mx][mx];
int n,m;
int c[mx][mx];
int ti[mx][mx];

int v[mx][mx];//minimum time for the vikings to reach this cell column or row //ragnar 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int can(int i,int j){
    if(i>=0&&i<n&&j<m&&j>=0&&a[i][j]!='I'){
        return 1;
    }return 0;
}

int x,y,X1,Y1,x2,y2;
int main()
{
cin>>n>>m;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
          cin>>a[i][j];
          c[i][j]=1e8;ti[i][j]=1e8;v[i][j]=1e8;
          if(a[i][j]=='Y'){
              x=i;y=j;
          } if(a[i][j]=='T'){
              X1=i;
              Y1=j;
          }if(a[i][j]=='V'){
              x2=i;y2=j;
          }
    }
  
}queue<pair<int,int>>q;
q.push({x2,y2});

c[x2][y2]=1;
while(!q.empty()){
    int mx,my,mv;
    pair<int,int>me=q.front();
    q.pop();
    mx=me.first;my=me.second;
   
    for(int i=0;i<4;i++){
        int nx=mx+dx[i];
        int ny=my+dy[i];
        if(can(nx,ny)&&c[nx][ny]>c[mx][my]+1){
            c[nx][ny]=c[mx][my]+1;
            q.push({nx,ny});
        }
    }
    
}

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(a[i][j]=='I'){
            continue;
        }
        for(int jj=j;jj>=0&&a[i][jj]!='I';jj--){
            v[i][j]=min(c[i][jj],v[i][j]);
        }
        for(int jj=j;jj<m&&a[i][jj]!='I';jj++){
            v[i][j]=min(c[i][jj],v[i][j]);
        }
        for(int jj=i;jj<n&&a[jj][j]!='I';jj++){
            v[i][j]=min(c[jj][j],v[i][j]);
        } for(int jj=i;jj>=0&&a[jj][j]!='I';jj--){
            v[i][j]=min(c[jj][j],v[i][j]);
        }
    }
}

queue<pair<int,int>>qq;
qq.push({x,y});ti[x][y]=1;
while(!qq.empty()){
    pair<int,int>me=qq.front();
    qq.pop();
    int mx=me.first;int my=me.second;
    int curent=ti[mx][my];
    for(int i=0;i<4;i++){
        int xx,yy;
        xx=mx+dx[i]; yy=my+dy[i];
        if(xx<n&&xx>=0&&yy<m&&yy>=0&&a[xx][yy]!='I'&&curent+1<ti[xx][yy]&&curent+1<v[xx][yy]){
           //cout<<curent+1<<" "<<xx<<" "<<yy<<" "<<v[xx][yy]<<endl;
           ti[xx][yy]=curent+1;
            qq.push({xx,yy});
        }
    }
    
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      // cout<<ti[i][j]<<" ";
    }//cout<<endl;
  
}

if(ti[X1][Y1]<100000000){cout<<"YES";}else{cout<<"NO";}

}