#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int dp[N];
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i]=max(dp[i-1],dp[i-2]+a[i]);
	}
	cout << dp[n];
}
