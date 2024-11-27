#include <bits/stdc++.h>
#include "function.h"
using namespace std;
using ll=long long int;
const int N=1e3+5;
ll dp[25][N],sum1[N],sum2[N];

long long minPenguinValue(int n, int m, std::vector<int> a){
	for(int i=1;i<=n;i++){
		sum1[i]=sum1[i-1]+a[i-1];
		sum2[i]=sum2[i-1]+a[i-1]*sum1[i];
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=1e18;
		}
	}
	dp[0][0]=0;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				dp[k][i]=min(dp[k][i],dp[k-1][j]+sum2[i]-sum2[j]-sum1[j]*(sum1[i]-sum1[j]));
				// sum [j]=sum [j-1+1];
			}
		}
	}
    return dp[m][n];
}
