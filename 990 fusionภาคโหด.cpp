#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5;
unordered_map<int,int> mp;
ll dp[N],a[N],sum[N];
vector<ll> p;
bitset<100005> qs;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    dp[i]=sum[i-1]*a[i]+dp[i-1];
    sum[i]=sum[i-1]+a[i];
    mp[a[i]]++;
  }
  if(m==0){
    cout << dp[n];
    return 0;
  }
  for(auto e:mp){
    int id=e.first;
    int cnt=e.second;
    int x=1;
    while(x<=cnt){
      p.push_back(id*x);
      cnt-=x;
      x*=2;
    }
    if(cnt!=0) p.push_back(id*cnt);
  }
  qs[0]=1;
  int x=sum[n]/2;
  for(auto e:p){
//  	cout <<e << "\n";
    qs|=(qs<<e);
  }
  for(int i=x;i>=0;i--){
    if(qs[i]==1){
      cout << dp[n]-i*(sum[n]-i);
      return 0;
    }
  }
}
