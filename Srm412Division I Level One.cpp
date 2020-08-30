/* Author : fadi gamal (handle : fadi57)
   problem name : TopCoder SRM 412 Division I Level One ForbiddenStrings
solution:let dp[i][1]= the number of non
 forbiden strings have the same last 2 digits
and dp[i][2]=the number of non
 forbiden strings haveing 2 diffrent last digits
then dp[i][1]=dp[i-1][1]+dp[i-1][2],
dp[i][2]=dp[i-1][2]+dp[i-1][1]*2

*/
#include <iostream>

using namespace std;
typedef long long ll;
ll dp[100][2];
int main() {
 ll n;
 cin>>n;
 dp[2][1]=3;
 dp[2][2]=6;
 for(int i=3;i<=n;i++){
     dp[i][2]=dp[i-1][2]+(dp[i-1][1]*2);
     dp[i][1]=dp[i-1][1]+dp[i-1][2];
 }
 
 cout<<dp[n][1]+dp[n][2];
}