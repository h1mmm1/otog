#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using piii=pair<pii,int>;
priority_queue<piii,vector<piii>,greater<piii>> q;
vector<pii> g[50005];
bool chk[50005];
int dis[50005][25];
bool vis[50005][25];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,p,k;
	cin >> n >> m >> p >> k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i=1;i<=p;i++){
		int a;
		cin >> a;
		chk[a]=true;
	}
	int s;
	cin >> s;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			dis[i][j]=1e9;
		}
	}
	dis[s][0]=0;
	q.push({{dis[s][0],s},0});
	while(!q.empty()){
		int l=q.top().first.first;
		int x=q.top().first.second;
		int cnt=q.top().second;
		q.pop();
		if(vis[x][cnt]==true) continue;
		vis[x][cnt]=true;
		for(auto e:g[x]){
			int xx=e.first;
			int ll=e.second;
			if(chk[xx]==true && dis[xx][cnt+1]>dis[x][cnt]+ll && vis[xx][cnt+1]==false){
				dis[xx][cnt+1]=dis[x][cnt]+ll;
				q.push({{dis[xx][cnt+1],xx},cnt+1});
			}
			if(vis[xx][cnt]==false && dis[xx][cnt]>dis[x][cnt]+ll){
				dis[xx][cnt]=dis[x][cnt]+ll;
				q.push({{dis[xx][cnt],xx},cnt});
			}
		}
	}
	if(vis[s][k]==false) cout << "NO FOOD :(";
	else cout << dis[s][k];
}
