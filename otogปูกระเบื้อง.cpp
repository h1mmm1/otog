#include<bits/stdc++.h>
using namespace std;
int dp1[1005];
int dp2[1005];
int dp3[1005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); 
	int n;
	cin >> n;
	dp1[0]=1;
	dp1[1]=1;
	dp2[1]=1;
	dp3[1]=1;
	int mod=1e9+7;
	for(int i=2;i<=n;i++){
		dp1[i]=dp1[i-1]+dp1[i-2]+dp2[i-2]+dp3[i-2];		
		dp2[i]=dp2[i-1]+dp1[i-1];
		dp3[i]=dp3[i-1]+dp1[i-1];
		dp1[i]%=mod;
		dp2[i]%=mod;
		dp3[i]%=mod;	
//		cout << i << ' ' << "dp1 " << dp1[i] << "\n";
//		cout << i << ' ' << "dp2 " << dp2[i] << "\n";
//		cout << i << ' ' << "dp3 " << dp3[i] << "\n";
	}
	cout << dp1[n];
}
