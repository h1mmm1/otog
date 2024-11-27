#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
priority_queue<pii,vector<pii>,greater<pii>> q;
const int N=1e6+5;
const int M=5e6+5;
vector<pii> g[M];
int a[N];
int dis[N];
bool vis[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,k,qq,r;
  cin >> n >> k >> qq >> r;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=k;i++){
    int u,v;
    cin >> u >> v;
    g[v].push_back({u,a[u]});
  }
  for(int i=1;i<=qq;i++){
    int y;
    cin >> y;
    for(int j=1;j<=n;j++){
      dis[j]=INT_MAX;
      vis[j]=false;
    } 
    dis[y]=a[y];
    q.push({dis[y],y});
    while(!q.empty()){
      int l=q.top().first;
      int x=q.top().second;
      q.pop();
      if(x==r){
        cout << dis[x] << '\n';
        break;
      }
      if(vis[x]==true) continue;
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
    while(!q.empty()) q.pop();
  }
//  for(int i=1;i<=n;i++){
//  	cout << dis[i] << ' ';
//  }
}



