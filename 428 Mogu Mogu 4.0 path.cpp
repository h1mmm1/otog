#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,MOD=100000003;
long long int dp[N][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  dp[0][1]=1;
  n++;
  m++;  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
//      dp[i][j]%=MOD;
    }
  }
//  for(int i=1;i<=n;i++){
//  	for(int j=1;j<=m;j++){
//  		cout << dp[i][j] << ' ';
//	  }
//	  cout << "\n";
//  }
  cout << dp[n][m];
}
