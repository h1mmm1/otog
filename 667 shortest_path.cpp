#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=10005;
vector<pii> g[N];
bool vis[N];
int dis[N];
priority_queue<pii,vector<pii>,greater<pii>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,s,t;
	cin >> n >> m >> s >> t;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i=0;i<=n;i++) dis[i]=1e9;
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second;
		q.pop();
		if(x==t){
			cout << dis[t];
			return 0;
		}
		if(vis[x]) continue;
		vis[x]=true;
		for(auto e:g[x]){
			int xx=e.first;
			int ll=e.second;
			if(dis[xx]>dis[x]+ll && vis[xx]==false){
				dis[xx]=dis[x]+ll;
				q.push({dis[xx],xx});
			}
		}
	}
}
