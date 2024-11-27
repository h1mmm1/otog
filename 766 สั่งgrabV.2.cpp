#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
priority_queue<pii,vector<pii>,greater<pii>> q;
vector<pii> g[300005];
vector<pii> d[300005];
vector<int> idx;
bool vis[55][30100];
int dis[55][30100];
int mp[30100];

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
    mp[a]=i;
    for(int j=0;j<=n;j++) dis[i][j]=INT_MAX;
    dis[mp[a]][a]=0;
    q.push({dis[mp[a]][a],a});
    while(!q.empty()){
      int l=q.top().first;
      int x=q.top().second;
      q.pop();
      if(vis[mp[a]][x]==true) continue;
      vis[mp[a]][x]=true;
      for(auto e:g[x]){
        int xx=e.first;
        int ll=e.second;
        if(vis[mp[a]][xx]==false && dis[mp[a]][xx]>dis[mp[a]][x]+ll){
          dis[mp[a]][xx]=dis[mp[a]][x]+ll;
          q.push({dis[mp[a]][xx],xx});
        }
      }
    }  
	} 
	for(int i=1;i<=p;i++){
		int s,x,t;
		cin >> s >> x >> t;
	   cout << dis[mp[x]][t]+dis[mp[x]][s] << "\n";
	}
	
}
