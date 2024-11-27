#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<ll,ll>;
const int N=1e5+5;
ll a[N],b[N],c[N],d[N];
vector<pii> p;
set<pii> s;

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
  for(int i=1;i<=n;i++){
    ll x=a[i]-c[i];
    ll y=b[i]-d[i];
    p.push_back({x,y});
  }
  p.push_back({0,0});
  sort(p.begin(),p.end());
//  s.insert({0,0});
  ll mn=8e18;
  int id=0;
  for(auto e:p){
    ll x=e.first;
    ll y=e.second;
    while(x-p[id].first>=sqrt(mn) && id<p.size()) s.erase({p[id].second,p[id].first}),id++;
    auto v=s.lower_bound({y-sqrt(mn),x});
    auto u=s.upper_bound({y+sqrt(mn),x});
    for( ;v!=u;v++){
      ll xx=x-(v->second);
      ll yy=y-(v->first);
      mn=min(mn,xx*xx+yy*yy);
    }
    s.insert({y,x});
  }
  cout << mn;
}

