#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> g[100005];
priority_queue<pii,vector<pii>,greater<pii>> q;
int dis[100005];
bool vis[100005];
int a[100005];
vector<int> ans;

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
  for(int i=0;i<n;i++){
    dis[i]=1e9;
  }
  dis[s]=0;
  q.push({dis[s],s});
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
        a[xx]=x;
      }
    }
  }
  cout << dis[t] << "\n";
  while(t!=s){
    ans.push_back(t);
    t=a[t];
  }
  cout << ans.size()+1 << "\n" << s << ' ';
  for(int i=ans.size()-1;i>=0;i--){
    cout << ans[i] << ' ';
  }
}
