#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int pa[N],dp[N];
vector<int> g[N];
bool vis[N];

inline void rec(int x){
	for(auto e:g[x]){
		if(vis[e]) continue;
		vis[e]=true;
		dp[e]=dp[x]+1;
		rec(e);
	}
}

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

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,t;
	cin >> n >> m >> t;
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		U(a,b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1;i<=t;i++){
		int a;
		cin >> a;
		dp[a]=1;
		vis[a]=true;
		rec(a);
	}
	int k;
	cin >> k;
	for(int i=1;i<=k;i++){
		int u,v;
		cin >> u >> v;
		if(find(v)!=find(u)) cout << "NO\n";
		else{
			if(dp[v]<dp[u]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
//	for(int i=1;i<=n;i++) cout << dp[i] << ' ';
}
/*
6 4 2
3 4
2 4
1 4
5 6
2 6
2
1 5
3 2
*/
