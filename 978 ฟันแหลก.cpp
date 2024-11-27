#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
map<ll,ll> mp;

int main(){
	ll t,ans=0;
	scanf("%d",&t);
	while(t--){
		ll s,c;
		scanf("%d%d",&s,&c);
		mp[s]=c;
	}
	for(auto e:mp){
		if(e.second%2==1) ans++;
		if(e.second>1){
			mp[e.first*2]+=e.second/2;
		}
	}
	cout << ans;
}
