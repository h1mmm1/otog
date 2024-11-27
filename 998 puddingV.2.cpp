#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int dp[N],a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		unordered_set<int> s;
		int mx=0;
		for(int j=i;j>0;j--){
			s.insert(a[j]);
			mx=max(mx,a[j]);
			int x=s.size();
			dp[i]=max(dp[i],dp[j-1]+x*mx);
		}
	}
	cout << dp[n];
}
