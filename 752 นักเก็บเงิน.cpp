#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> dp[i];
		dp[i]+=dp[i-1];
	}
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
	}
	for(int i=1;i<=m;i++){
		int m;
		cin >> m;
		auto v=lower_bound(dp+1,dp+1+n,m)-dp;
		if(v-1==n) cout << "-1\n"; 
		else cout << v-1 << "\n";
	}
}
