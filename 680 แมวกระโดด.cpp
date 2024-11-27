#include<bits/stdc++.h>
using namespace std;
int a[105][105][105];
int dp[105][105][105];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int l=1;l<=k;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> a[l][i][j];
			}
		}
	}
	for(int l=1;l<=k;l++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        int b=max(dp[l][i-1][j],dp[l][i][j-1]);
        if(b!=0 || l==1) dp[l][i][j]=b+abs(a[l][i][j]);
        if(a[l-1][i][j]<0 && dp[l-1][i][j]>0){
          dp[l][i][j]=max(dp[l][i][j],dp[l-1][i][j]+abs(a[l][i][j]));
        } 
      }
    }
  }
	int ans=0;
	for(int i=1;i<=k;i++){
		ans=max(ans,dp[i][n][m]);
	}
	cout << ans;
	/*
	for(int l=1;l<=k;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout << dp[l][i][j] << ' ';
			}
			cout << "\n";
		}
		cout << "\n";

	}
	*/
}

