#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		ll a;
		cin >> a;
		p.push_back(a);
	}
	sort(p.begin(),p.end());
	for(int i=1;i<=n;i++){
		p[i]+=p[i-1];
	}
	for(int i=1;i<=m;i++){
		ll x;
		cin >> x;
		auto v=upper_bound(p.begin(),p.end(),x)-p.begin();
		cout << v << "\n";
	}
}
