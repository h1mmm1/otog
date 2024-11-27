#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll a[100005];
ll b[100005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=n;i++){
    b[i]=a[i]+a[i-1]+a[i+1];
    b[i]=max(b[i],b[i-1]);
  }
  while(m--){
    int x;
    cin >> x;
    auto v=lower_bound(b+1,b+n+1,x)-b;
    if(v==n) cout << "-1" << "\n";
    else cout << v << "\n";
  }
//	for(int i=1;i<=n;i++){
//		cout << b[i] << " ";
//	}
}

