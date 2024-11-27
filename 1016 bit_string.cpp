#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e6+5e5+5;
ll a[N],sum[25],dp[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	int cnt=(1<<n)/2;
	for(int i=0;i<n;i++){
		sum[i]=cnt;
		cnt/=2;
	}
	for(int i=1;i<=(1<<n);i++){
		string s;
		int x,t=0;
		cin >> s >> x;
		for(int j=0;j<s.size();j++){
			if(s[j]=='1'){
				t+=sum[j];
			}
		}
		a[t]=x;
//		cout << t << ' ';
	}
	for(int i=0;i<(1<<n);i++) dp[i]=-1e18;
//	memset(dp,-0x3f,sizeof dp);
	dp[0]=0;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i&(1<<j))==0){
				dp[(i|(1<<j))]=max(dp[i]+a[(i|(1<<j))],dp[(i|(1<<j))]);
//				cout << i << ' ' << (1<<j) << ' ' << (i&(1<<j)) << ' ' << a[(i|(1<<j))] << "\n";
			}
			if((i&(3<<j))==0){
				dp[(i|(3<<j))]=max(dp[i]+a[(i|(3<<j))],dp[(i|(3<<j))]);
			}			
		}
	}
	while(m--){
		string s;
		cin >> s;
		int t=0;
		for(int j=0;j<s.size();j++){
			if(s[j]=='1'){
				t+=sum[j];
			}
		}
		cout << dp[t] << "\n";
	}
//	for(int i=0;i<(1<<n);i++){
//		cout << dp[i] << ' ';	
//	}
}
