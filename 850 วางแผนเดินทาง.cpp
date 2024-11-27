#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using piii=pair<int,pii>;
int a[1005];
vector<pii> g[1005];
int dis[1005][105];
bool vis[1005][105];
priority_queue<piii,vector<piii>,greater<piii>> q;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=m;i++){
    int d,b,c;
    cin >> d >> b >> c;
    g[d].push_back({b,c});
    g[b].push_back({d,c});
  }
  int p;
  cin >> p;
  while(p--){
    int c,u,v;
    cin >> c >> u >> v;
    for(int i=0;i<=n;i++){
      for(int j=0;j<=c;j++){
        dis[i][j]=1e9;
      }
    }
    dis[u][0]=0;
    q.push({dis[u][0],{u,0}});
    while(!q.empty()){
      int l=q.top().first;
      int x=q.top().second.first;
      int oil=q.top().second.second;
      q.pop();
      if(vis[x][oil]==true) continue;
      vis[x][oil]=true;
      //cout << l << ' ' << x << ' ' << oil << "\n";
      if(oil!=c && dis[x][oil+1]>dis[x][oil]+a[x]){
        dis[x][oil+1]=dis[x][oil]+a[x];
        q.push({dis[x][oil+1],{x,oil+1}});
      }
      for(auto e:g[x]){
        int xx=e.first;
        int ll=e.second;
        if(oil-ll>=0 && vis[xx][oil-ll]==false && dis[xx][oil-ll]>dis[x][oil]){
          dis[xx][oil-ll]=dis[x][oil];
          q.push({dis[xx][oil-ll],{xx,oil-ll}});
        }
      }
    }
    int ans=1e9;
    for(int i=0;i<=c;i++){
      ans=min(ans,dis[v][i]);
	}
    if(ans==1e9) cout << "impossible" << "\n";
    else cout << ans << "\n";
    for(int i=0;i<=n;i++){
      for(int j=0;j<=c;j++){
        dis[i][j]=0;
        vis[i][j]=false;
      }
    }
  }
}
