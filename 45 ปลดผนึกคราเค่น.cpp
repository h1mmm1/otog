#include<bits/stdc++.h>
using namespace std;
int dp[1050][1050];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,k,ans;
  cin >> n >> m >> k;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      int a;
      cin >> a;
      dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(i-k>=0 && j-k>=0){
        ans=max(ans,dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
      } 
    }
  }
  /*
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout << dp[i][j] << ' ';
    }
    cout << "\n";
  }
  */
  cout << ans;
}
