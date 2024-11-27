#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<int,int>;
using ppi=pair<ll,pii>;
const int N=1e5+5;
vector<ppi> p;
int pa[N];
unordered_set<ll> ans[N];

inline int find(int v){
	if(pa[v]==v) return v;
	return pa[v]=find(pa[v]);
}

inline void U(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b) pa[a]=b;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0;i<=n;i++) pa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		u++,v++;
		p.push_back({w,{u,v}});
		if(find(u)!=find(v)) U(u,v);
	}
	for(auto e:p){
		int w=e.first;
		int u=e.second.first;
		int v=e.second.second;
		int x=find(u);
		ans[x].insert(pow(2,w));
	}
	while(k--){
		int u,v;
		cin >> u >> v;
		u++,v++;
		ll cnt=0;
		int a=find(u),b=find(v);
//		cout << a << ' ' << b << "\n";
		if(a!=b) cout << "-1\n";
		else{
			for(auto e:ans[a]){
				cnt+=e;
//				cout << e << "\n";
			}
			cout << cnt << "\n";
		}
	}
//	for(int i=1;i<=n;i++) cout << find(i) << ' ';
}
