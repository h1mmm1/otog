#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5,M=105;
ll dp[N][M],x[N][M];
// [N]=t 
// [105]=x
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n,m,s;
	cin >> n >> m >> s;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		x[a][b]=c;
	}	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dp[i][j]=LLONG_MIN;
		}
	}
	dp[0][s]=0;
	for(int i=1;i<N;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]})+x[i][j];
		}
	}
	ll mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,dp[N-1][i]);
	}
//	for(int i=1;i<N;i++){
//		for(int j=1;j<=5;j++){
//			cout << dp[i][j] << ' ';
//		}
//		cout << "\n";
//	}
	cout << mx;
}
