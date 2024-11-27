#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ppi=pair<int,pii>;
const int N=505,M=2005;
int a[N],dis[N][M],ans[M];
bool vis[N][M];
vector<pii> g[N];
priority_queue<ppi,vector<ppi>,greater<ppi>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,t;
	cin >> n >> m >> t;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	memset(dis,0x3f,sizeof dis);
	dis[1][0]=0;
	q.push({0,{1,0}});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second.first;
		int c=q.top().second.second;
		q.pop();
//		cout << l << ' ' << x << ' ' << c << "\n";
		if(vis[x][c]) continue;
		for(auto e:g[x]){
			int xx=e.first;
			int ll=e.second;
			int sum=a[x]+c;
			if(!vis[xx][sum] && dis[xx][sum]>dis[x][c] && sum<M){
				dis[xx][sum]=dis[x][c];
				q.push({dis[xx][sum],{xx,sum}});
			}
			if(!vis[xx][c] && dis[xx][c]>dis[x][c]+ll){
				dis[xx][c]=dis[x][c]+ll;
				q.push({dis[xx][c],{xx,c}});	
			}
		}
	}
	ans[0]=dis[n][0];
	for(int i=1;i<M;i++){
		ans[i]=min(ans[i-1],dis[n][i]);
//		cout << ans[i-1] << ' ' << dis[n][i] << "\n";
	}
	while(t--){
		int x;
		cin >> x;
		cout << ans[x] << "\n";
	}
//	for(int i=0;i<=20;i++){
//		cout << i << ' ' << dis[n][i] << '\n';
//	}
}
