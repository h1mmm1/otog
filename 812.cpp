#include<bits/stdc++.h>
using namespace std;
const int N=25,M=1e9;
int a[N+1][N+1];
int dp[(1<<N)];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&a[i][j]);
    }
  }
  for(int i=1;i<(1<<n);i++) dp[i]=M;
  for(int i=1;i<(1<<n);i++){
    int k=__builtin_popcount(i);
    int tmp=i;
    int t=__builtin_ctz(tmp);
    tmp>>=(t);
    for(int j=t;j<n;j++){
      dp[i]=min(dp[i],dp[i^(1<<j)]+a[k][j]);
      tmp>>=1;
      t=__builtin_ctz(tmp);
      tmp>>=t;
      j+=t;
    }  
  }
  printf("%d",dp[(1<<n)-1]);
}  
