#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=105,MOD=5454541;
ll a[N],dp[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	ll ans=n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int L=2;L<=n;L++){
		dp[0][0]=1;
		for(int i=1;i<=n;i++){		
			int tmp=a[i]%L;
			for(int k=i;k>0;k--){
				for(int j=0;j<=n;j++){
					dp[k][j]+=dp[k-1][(j-tmp+L)%L];
					dp[k][j]%=MOD;
				}
			}
		}
		ans+=dp[L][0];
		ans%=MOD;
		memset(dp,0,sizeof dp);
	}
	cout << ans;
}

