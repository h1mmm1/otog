#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=1e5+5;
vector<pii> tp[2];
vector<int> g[N];
int vis[N],pa[N];

inline int find(int v){
	if(pa[v]==v) return v;
	return pa[v]=find(pa[v]);
}

inline void U(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		pa[a]=b;
	}
}

inline void rec(int x){
	vis[x]=1;
	for(auto e:g[x]){
		if(vis[e]==0) rec(e);
		vis[x]=max(vis[x],vis[e]+1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b;
		char c;
		cin >> a >> b >> c;
		if(c=='='){
			if(find(a)!=find(b)) U(a,b);
		}
		else if(c=='>') tp[0].push_back({a,b});
		else tp[1].push_back({b,a});
	}
	for(auto e:tp[0]){
		int a=find(e.first);
		int b=find(e.second);
		g[a].push_back(b);
	}
	for(auto e:tp[1]){
		int a=find(e.first);
		int b=find(e.second);
		g[a].push_back(b);
	}
//	for(int i=1;i<=n;i++){
//		for(auto e:g[find(i)]){
//			cout << e << ' ';
//		}
//		cout << "\n";
//	}	
	for(int i=1;i<=n;i++){
		int v=find(i);
		if(vis[v]==0) rec(v);
		cout << vis[v] << "\n";
	}	
}
