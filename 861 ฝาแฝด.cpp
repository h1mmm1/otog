#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=50005;
ll a[N];
ll b[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,q;
  cin >> n >> q;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    a[i]+=a[i-1];
  }
  for(int i=1;i<=n;i++){
    cin >> b[i];
    b[i]+=b[i-1];
  }
  for(int i=1;i<=n;i++){
    a[i]=max(a[i],a[i-1]);
    b[i]=max(b[i],b[i-1]);
  }
  while(q--){
    ll m;
    ll mn=LLONG_MAX;
    cin >> m;
    ll l=0,r=m;
    while(l<r){
      ll mid=(l+r)/2;
      ll x=m-mid,y=mid;
      auto v=lower_bound(a+1,a+n+1,x)-a;
      auto u=lower_bound(b+1,b+1+n,y)-b;
      ll uu=u;
      ll vv=v;
      mn=min(mn,max(uu,vv));
      if(vv==uu) break;
      else if(vv<uu){
        r=mid;
      }
      else l=mid+1;
    }
    if(mn>n) cout << n << "\n";
    else cout << mn << "\n";
  }
//  for(int i=1;i<=n;i++){
//  	cout << a[i] << ' ';
//  }
//  cout << "\n";
//  for(int i=1;i<=n;i++){
//  	cout << b[i] << ' ';
//  }
}

//1  2 6  5 -3   4 -7  8  9  2
//1 -2 3  4  5 -10  8 -4  5 15
//
//1  3 9 14 11  15  8 16 25 27
//1 -1 2  6 11   1  9  5 10 25
//
//1 3 9 14 14 15 15 16 25 27
//1 1 2  6 11 11 11 11 11 25



