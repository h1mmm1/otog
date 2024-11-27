//https://cp-algorithms.com/graph/bridge-searching.html
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<ll,ll>;
const int N=1e5+5;
vector<pii> g[N],gg[N];
ll dis[N],low[N],cnt=0;
bool vis[N];
vector<pii> pp;

inline void rec(int x,int p){
  cnt++;
  dis[x]=low[x]=cnt;
  for(auto r:gg[x]){
    int e=r.first;
    if(e==p) continue;
    if(dis[e]==0){
      rec(e,x);
      low[x]=min(low[x],low[e]);
      if(low[e]>dis[x]){
        pp.push_back({x,e});
        // cout << x << ' ' << e << "\n";
      }  
      else{
        g[x].push_back({e,r.second});
        g[e].push_back({x,r.second});
      }
    }
    else{
      low[x]=min(low[x],dis[e]);
      g[x].push_back({e,r.second});
      g[e].push_back({x,r.second});      
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=1;i<=m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    gg[a].push_back({b,c});
    gg[b].push_back({a,c});
  }
//  for(int i=1;i<=n;i++){
//    dp[i]++;
//  }  
  rec(1,1);
  while(k--){
    int a,b;
    cin >> a >> b;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    bool ok=true;
    for(int i=0;i<=n;i++) dis[i]=1e18;
//    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    dis[a]=0;
    q.push({dis[a],a});
    while(!q.empty()){
      ll l=q.top().first;
      int x=q.top().second;
      q.pop();
      if(x==b){
        ok=false;
        cout << l << "\n";
        break;
      }
      if(vis[x]) continue;
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
    if(ok==true) cout << "-1\n";
  }
} 

