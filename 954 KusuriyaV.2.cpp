#include<bits/stdc++.h>
using namespace std;
const int N=20;
long long int dp[(1<<N)];
vector<pair<int,int>> p;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<(1<<m);i++) dp[i]=1e18;
  dp[0]=0;
  for(int i=1;i<=n;i++){
    long long int k;
    int st=0;
    cin >> k;
    for(int j=0;j<m;j++){
      int x;
      cin >> x;
      if(x==1) st|=(1<<(j));
    }
    if(dp[st]>k){
      dp[st]=k;
      p.push_back({st,k});
    }
//    dp[st]=min(dp[st],k);
  }
  for(auto e:p){
    int st=e.first;
    int k=e.second;
    if(k>dp[st]) continue;
    for(int j=0;j<(1<<m);j++){
      dp[st|j]=min(dp[st|j],dp[j]+k);
    }
  }
//  for(int i=0;i<=(1<<m);i++){
//  	cout << dp[i] << "\n";
//  }
  cout << dp[(1<<m)-1];
}
