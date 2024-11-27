#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=5e6+5;
int a[N];
ll dp[N],sum[N];
deque<pair<ll,ll>> dq;

int main(){
//  ios::sync_with_stdio(0); cin.tie(0);
  int n;
//  cin >> n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  dq.push_back({a[0],0});
  for(int i=1;i<=n;i++){ 
    while(!dq.empty() && dq.back().first>a[i]) dq.pop_back();
    dp[i]=dp[dq.back().second]+(a[i]*(i-dq.back().second));
    dq.push_back({a[i],i});
  }
  while(!dq.empty()) dq.pop_back();
  dq.push_back({a[n+1],n+1});
  ll ans=0;
  for(int i=n;i>=1;i--){
    while(!dq.empty() && dq.back().first>a[i]) dq.pop_back();
    sum[i]=sum[dq.back().second]+(a[i]*(dq.back().second-i));
    dq.push_back({a[i],i});
    ans=max(ans,dp[i]+sum[i]-a[i]);
  }
  printf("%lld",ans);
//  cout << ans;
//	cout << "\n";
//	for(int i=1;i<=n;i++) cout << dp[i] << ' ';
//	cout << '\n';
//	for(int i=1;i<=n;i++) cout << sum[i] << ' ';
}   

