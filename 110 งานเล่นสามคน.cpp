#include<bits/stdc++.h>
using namespace std;
long long int a[50],dp[10000];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,sum=0,ans=0;
	cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;i++) a[i]=i,sum+=i;
	if(sum%2==1){
		cout << '0';
		return 0;
	}	
	
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
//			if(dp[sum/2]==1){
//				ans++;
//				dp[sum/2]=0;
//				cout << a[i] << "\n";
//			}
		}
	}
	cout << dp[sum/2]/2;
}

