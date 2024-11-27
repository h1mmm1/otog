#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using ppi=pair<ll,ll>;
const int N=65;
int a[N];
vector<ppi> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	ll cnt=1,ans=0;
	for(int i=1;i<=n;i++){
		int b;
		cin >> b;
		if(a[i]==1) ans+=cnt;
		else{
			p.push_back({cnt,b});
		}
		cnt*=2;
	}
	sort(p.begin(),p.end(),greater<ppi>());
	for(auto e:p){
		ll l=e.first;
		ll x=e.second;
		if(m>=x){
			ans+=l;
			m-=x;
		}
	}
	cout << ans;
}
