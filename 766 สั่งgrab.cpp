#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
priority_queue<pii,vector<pii>,greater<pii>> q;
vector<pii> g[300005];
vector<pii> d[300005];
vector<int> idx;
bool vis[30100];
int dis[30100];
int ans[30100];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k,p;
	cin >> n >> m >> k >> p;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i=1;i<=k;i++){
		int a;
		cin >> a;
		idx.push_back(a);
	}
	for(int i=1;i<=p;i++){
		int s,x,t;
		cin >> s >> x >> t;
		d[x].push_back({s,t});
	}
	int cnt=0;
	for(auto b:idx){
		for(auto c:d[b]){
			cnt++;
			for(int i=0;i<=n;i++){
				vis[i]=false;
				dis[i]=1e9;
			}
			dis[b]=0;
			q.push({dis[b],b});
			while(!q.empty()){
				int l=q.top().first;
				int x=q.top().second;
				q.pop();
				if(vis[x]==true) continue;
				vis[x]=true;
				for(auto e:g[x]){
					int xx=e.first;
					int ll=e.second;
					if(vis[xx]==false && dis[xx]>dis[x]+ll){
						dis[xx]=dis[x]+ll;
						q.push({dis[xx],xx});
					}
				}
			}
			ans[cnt]=dis[c.first]+dis[c.second];
			//cout << cnt << "\n";
			
		}
	}
	for(int i=1;i<=p;i++){
		cout << ans[i] << "\n";
	}
}
