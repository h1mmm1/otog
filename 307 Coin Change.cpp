#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int dp[N],a[25];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<N;i++) dp[i]=1e9;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<N;j++){
			dp[j]=min(dp[j],dp[j-a[i]]+1);
		}
	}
//	for(int i=1;i<=m;i++) cout << dp[i] << ' ';
	cout << dp[m];
}
