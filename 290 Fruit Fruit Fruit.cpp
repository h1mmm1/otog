#include<bits/stdc++.h>
using namespace std;
int a[1050][1050];
int dp[1050][1050];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> a[i][j];
    }
  }
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
    }
  }
  cout << dp[n][m];
}
