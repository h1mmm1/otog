#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],dp[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=2*n;i++){
		cin >> a[i];
	}
	for(int k=0;k<2*n;k++){
		for(int l=1;l<=2*n-k;l++){
			int r=l+k;
			dp[l][r]=max(dp[l+2][r]+a[l],dp[l][r-2]+a[r]);
			dp[l][r]=max({dp[l+1][r-1]+a[l],dp[l+1][r-1]+a[r],dp[l][r]});
			
		}
	}
//	for(int i=1;i<=2*n;i++){
//		for(int j=1;j<=2*n;j++){
//			cout << dp[i][j] << ' ';
//		}
//		cout << "\n";
//	}
	cout << dp[1][2*n];
}
