#include<bits/stdc++.h>
using namespace std;
const int N=123457;
int c[N];
int r[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> c[i];
  }
  for(int i=1;i<=m;i++){
    cin >> r[i];
  }
  long long int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      ans+=min(c[i],r[j]);
    }
  }
  cout << ans;
}

