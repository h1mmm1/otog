#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=2e5+5;
ll x[N],y[N];
vector<ll> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n,zx,zy,r;
	cin >> n >> zx >> zy >> r;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i];
		ll w=(x[i]-zx)*(x[i]-zx)+(y[i]-zy)*(y[i]-zy);
		if(w<=1ll*r*r) p.push_back(i);
	}
//	cout << 
	ll cnt=LLONG_MAX,sum=LLONG_MAX;
	for(auto e:p){
		cnt=min(cnt,abs(x[1]-x[e])+abs(y[1]-y[e]));
		sum=min(sum,abs(x[n]-x[e])+abs(y[n]-y[e]));
	}
	if(cnt==LLONG_MAX) cout << abs(x[1]-x[n])+abs(y[1]-y[n]);
	else cout << min(cnt+sum,abs(x[1]-x[n])+abs(y[1]-y[n]));
	return 0;
}

