#include <bits/stdc++.h>
#include "stairs.h"
using namespace std;
const int N=1e5+5,MOD=1e9+7;
int a[N];
long long int dp[N];

int countWays(int n, int m, std::vector<int> S){
	for(int i=1;i<=m;i++) a[i]=S[i-1];
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i-a[j]>=0) dp[i]+=dp[i-a[j]],dp[i]%=MOD;
		}
	}
    return dp[n];
}
