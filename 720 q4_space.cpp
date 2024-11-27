#include<bits/stdc++.h>
using namespace std;
using lll=long long int;
using pii=pair<lll,lll>;
using ppi=pair<pii,lll>;
unordered_map<string,lll> mp;
const int N=5e4+5;
vector<pii> dis[N],g[N];
lll id[N];
priority_queue<ppi,vector<ppi>,greater<ppi>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string a,b;
	lll n,m,k;
	cin >> n >> m >> a >> b >> k;
	for(int i=1;i<=n;i++){
		string p;
		lll t;
		cin >> p >> t;
		mp[p]=i;
		id[i]=t;
	}
	for(int i=1;i<=m;i++){
		string d,f;
		lll gg;
		cin >> d >> f >> gg;
		lll uu=mp[d],vv=mp[f];
		g[uu].push_back({vv,gg});
		g[vv].push_back({uu,gg});
	}
	lll st=mp[a];
	q.push({{id[st],st},0});
	while(!q.empty()){
		lll cnt=q.top().first.first;
		lll x=q.top().first.second;
		lll l=q.top().second;
		q.pop();
//		cout << cnt  << ' ' << x << ' ' << l << "\n";
		for(auto e:g[x]){
			lll xx=e.first;
			lll ll=e.second;
			if(l+ll>k) continue;
			bool chk=true;
			lll mx=max(cnt,id[xx]);
			for(auto r:dis[xx]){
				if(mx>=r.first && l+ll>=r.second){
					chk=false;
					break;
				}
			}
			if(chk){
				dis[xx].push_back({mx,l+ll});
				q.push({{mx,xx},l+ll});
			}
		}
	}
	lll ans1=1e18,ans2=1e18;
	for(auto e:dis[mp[b]]){
		if(ans1>e.first) ans1=e.first,ans2=e.second;
		else if(ans1==e.first) ans2=min(ans2,e.second);
	}
	cout << ans1 << ' ' << ans2;
}
