#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5;
ll dp[N];
vector<int> g[N];

void rec(int x){
  for(auto e:g[x]){
    dp[e]+=dp[x];
    rec(e);
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n-1;i++){
    int v,u;
    cin >> v >> u;
    g[u].push_back(v);
  }
  for(int i=1;i<=m;i++){
    int v,u;
    cin >> v >> u;
    dp[v]+=u;
  }
  rec(1);
  for(int i=1;i<=n;i++){
    cout << dp[i] << '\n';
  }
}

