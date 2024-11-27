#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N][N],dp[N][N];

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
			if(j==1) dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+a[i][j];
			else if(j==m) dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+a[i][j];
			else dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]})+a[i][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	int mn=1e9;
	for(int j=1;j<=m;j++){
		mn=min(mn,dp[n][j]);
	}
	cout << mn;
}
