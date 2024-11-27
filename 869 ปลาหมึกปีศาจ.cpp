#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=1e5+5;
vector<pii> g[N];
int dp[N],n,k,sum[N],vis[N];

inline void rec(int x,int p){
//	cout << x << ' ' << p << "\n";
	vis[x]=p;
	for(auto e:g[x]){
		int xx=e.first;
		int ll=e.second;
		if(vis[xx]!=0) continue;
		if(xx==p) continue;
		dp[xx]+=dp[x]+ll;
		rec(xx,p);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for(int i=1;i<=k;i++){
		int w;
		cin >> w;
		if(i==k) sum[0]=w+sum[i];
		else sum[i+1]=w+sum[i];
	}
	for(int i=1;i<=n-k;i++){
		int u,w;
		cin >> u >> w;
		g[u].push_back({k+i,w});
		g[k+i].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		rec(i,i);		
	}
//	for(int i=1;i<=n;i++) cout << sum[i] << "\n";
	int t;
	cin >> t;
	while(t--){
		int u,v;
		cin >> u >> v;
		if(vis[u]==vis[v]) cout << abs(dp[v]-dp[u]) << "\n";
		else{
			int p=abs(sum[vis[u]]-sum[vis[v]]);
//			cout << sum[u] << ' ' << sum[v] << ' ' << sum[k] << "\n";
			cout << dp[v]+dp[u]+min(p,sum[0]-p) << "\n";
		}
	}
//	for(int i=1;i<=n;i++){
//		cout << dp[i] << "\n";
//	}
}
