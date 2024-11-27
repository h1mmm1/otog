#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,MOD=1e6+3;
int a[]={0,50,25,10,5,1};
long long int dp[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		dp[0]=1;
		for(int i=1;i<=5;i++){
			for(int j=a[i];j<N;j++){
				dp[j]+=dp[j-a[i]];
				dp[j]%=MOD;
			}
		}
		cout << dp[n]%MOD << "\n";
		memset(dp,0,sizeof dp);
	}
}
