#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long int dp[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(dp,0,sizeof dp);
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			int x;
			cin >> x;
			dp[i]+=dp[i-1]+x;
		}
		for(int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		x++;
		y++;
		cout << dp[y]-dp[x-1] << "\n";
		}
		cout << "\n";
	}
}
