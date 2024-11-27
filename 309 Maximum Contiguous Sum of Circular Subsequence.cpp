#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll dp[100005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll mx=INT_MAX,ans=INT_MIN,sum=0;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> dp[i];
    sum+=dp[i];
    dp[i]+=dp[i-1];
	
  }
  int l=0;
  for(int i=1;i<=n;i++){
    if(dp[i]>dp[l]) l=i;
    mx=min(mx,dp[i]-dp[l]);
    
  }
  l=0;
  for(int i=1;i<=n;i++){
    ans=max(ans,dp[i]-dp[l]);
    if(dp[i]<dp[l]) l=i;    
  }
  if(sum-mx==0){
  	cout << ans;
  	return 0;
  }
  cout << max(sum-mx,ans);
  //cout << ans << ' ' << sum-mx;
}

