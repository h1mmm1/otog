#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ppi=pair<int,pii>;
const int N=1e5+5;
vector<pii> g[N];
priority_queue<ppi,vector<ppi>,greater<ppi>> q;
int dis[N][5];
bool vis[N][5];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k,st,tp;
	cin >> n >> m >> k >> st >> tp;
	k++;
	for(int i=1;i<=m;i++){
		int aa,b,c;
		cin >> aa >> b >> c;
		g[aa].push_back({b,c});
		g[b].push_back({aa,c});
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++){
			dis[i][j]=1e9;
		}
	}
	dis[st][0]=0;
	q.push({dis[st][0],{st,0}});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second.first;
		int t=q.top().second.second;
		q.pop();
		if(vis[x][t]) continue;
		vis[x][t]=true;
//		cout << l << ' ' << x << ' ' << t << "\n";
		if(x==tp && t==1){
			cout << l;
			return 0;
		}
		for(auto e:g[x]){
			int xx=e.first;
			int ll=e.second;
			int cnt=(t+1)%k;
			if(cnt==0) cnt=1;
			if(vis[xx][cnt]==false && dis[xx][cnt]>dis[x][t]+ll){
				dis[xx][cnt]=dis[x][t]+ll;
				q.push({dis[xx][cnt],{xx,cnt}});
			}
		}
	}
	cout << "-1";
}
