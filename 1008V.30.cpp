#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<ll,ll>;
const int N=1e5+5;
ll a[N],b[N],c[N],d[N];
vector<pii> p;
set<pii> s;
set<ll> s1;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    a[i]+=a[i-1];
  }
  for(int i=1;i<=n;i++){
    cin >> b[i];
    b[i]+=b[i-1];
  }
  for(int i=1;i<=n;i++){
    cin >> c[i];
    c[i]+=c[i-1]; 
  }
  for(int i=1;i<=n;i++){
    cin >> d[i];
    d[i]+=d[i-1];
  }
  ll mn=LLONG_MAX;

  if(b[n]==0 && d[n]==0){
    s1.insert(0);
    for(int i=1;i<=n;i++){
      ll x=a[i]-c[i],y;
      auto v=s1.lower_bound(x);
      if(v!=s1.end()){
        y=*v;
        if(abs(x-y)<=sqrt(mn)) mn=min(mn,(x-y)*(x-y));
      }
      if(v!=s1.begin()){
        v--;
        y=*v;
        if(abs(x-y)<=sqrt(mn)) mn=min(mn,(x-y)*(x-y));
      }
      s1.insert(x);
    }
  }
  else{
    for(int i=1;i<=n;i++){
      for(int j=i;j<=n;j++){
        ll x=(a[j]-c[j])-(a[i-1]-c[i-1]);
        ll y=(b[j]-d[j])-(b[i-1]-d[i-1]);
        if(abs(x)>sqrt(mn) || abs(y)>sqrt(mn)) continue;
        mn=min(mn,x*x+y*y);
      }
    }
  }
  cout << mn;
}
