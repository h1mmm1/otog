#include<bits/stdc++.h>
using namespace std;
int a[10005];
int dp[10005][105];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,cnt=0,mx=0;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  dp[1][0]=a[1];
  for(int i=2;i<=n;i++){
    for(int j=0;j<=m;j++){
      dp[i][j]=max(dp[i-1][j],dp[i-2][j]+a[i]);
    }
    for(int j=0;j<=m;j++){
      if(j+1<=m) dp[i][j+1]=max(dp[i-1][j]+a[i],dp[i][j+1]);
    }
  }
  for(int i=0;i<=m;i++){
    mx=max(mx,dp[n][i]);
  }
//  for(int i=1;i<=n;i++){
//  	cout << i << "= ";
//  	for(int j=0;j<=m;j++){
//  		cout << dp[i][j] << ' ';
//	  }
//	  cout << "\n";
//  }  
  cout << mx;
}

