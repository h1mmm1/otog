#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
priority_queue<pii,vector<pii>,greater<pii>> q;
vector<pii> g1[100005],g2[100005];
int dis1[100005];
int dis2[100005];
bool vis[100005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,f,s,t;
	cin >> n >> m >> f >> s >> t;
	for(int i=0;i<100005;i++){
		dis1[i]=dis2[i]=1e9;
	}
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		g1[a].push_back({b,c});
		g2[b].push_back({a,c});
	}
	dis1[s]=0;
	q.push({dis1[s],s});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second;
		q.pop();
		if(vis[x]==true) continue;
		vis[x]=true;
		for(auto e:g1[x]){
			int xx=e.first;
			int ll=e.second;
			if(vis[xx]==false && dis1[xx]>dis1[x]+ll){
				dis1[xx]=dis1[x]+ll;
				q.push({dis1[xx],xx});
			}
		}
	}
	memset(vis,false,sizeof vis);
	dis2[t]=0;
	q.push({dis2[t],t});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second;
		q.pop();
		if(vis[x]==true) continue;
		vis[x]=true;
		for(auto e:g2[x]){
			int xx=e.first;
			int ll=e.second;
			if(vis[xx]==false && dis2[xx]>dis2[x]+ll){
				dis2[xx]=dis2[x]+ll;
				q.push({dis2[xx],xx});
			}
		}
	}
	while(f--){
		int k;
		cin >> k;
		cout << dis1[k]+dis2[k] << "\n";
	}
//	for(int i=1;i<=n;i++){
//		cout << dis1[i] << ' ' << dis2[i] << "\n";
//	}
}
