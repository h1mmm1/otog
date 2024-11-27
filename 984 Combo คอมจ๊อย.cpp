#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=1e4+5;
vector<pii> g[N];
int dis[N];
priority_queue<pii,vector<pii>,greater<pii>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,qq,k,p,s;
	cin >> n >> m >> qq >> k >> p >> s;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
	}
	for(int i=1;i<=n;i++) dis[i]=1e9;
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second;
		q.pop();
		if(x==p) dis[x]=0;
		if(dis[x]>k) continue;		
		for(auto e:g[x]){
			int xx=e.first;
			int ll=e.second;
			if(dis[xx]>dis[x]+ll){
				dis[xx]=dis[x]+ll;
				if(dis[x]+ll<=k) q.push({dis[xx],xx});
			}
		}
	}
	while(qq--){
		int x;
		cin >> x;
//		cout << dis[x] << "\n";
		if(dis[x]<=k) cout << k-dis[x] << "\n";
		else cout << "-1\n";
	}
}
