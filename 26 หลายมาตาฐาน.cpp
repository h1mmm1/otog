#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
unordered_set<int> s[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=m;i++){
    int a,b;
    cin >> a >> b;
    s[a].insert(b);
  }
  for(int i=1;i<=n;i++){
    cout << i << ' ' << s[i].size() << '\n';
  }
}
