#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],dp[N][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n+1;i++){
    cin >> a[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      dp[i][j]=1e9;
    }
    dp[i][i]=0;
  }
  for(int i=1;i+1<=n;i++){
    dp[i][i+1]=a[i]*a[i+1]*a[i+2];
  }
  
  for(int i=2;i<=n;i++){
    for(int j=1;i+j<=n;j++){
      for(int k=j;k+1<=i+j;k++){
        dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+a[j]*a[k+1]*a[i+j+1]);
      }
    }
  }
//  for(int i=1;i<=n;i++){
//    for(int j=1;j<=n;j++){
//      if(j>=i) cout << dp[i][j] << ' ';
//      else cout << '\t';
//    }
//    cout << "\n";
//  }
  cout << dp[1][n];
}
