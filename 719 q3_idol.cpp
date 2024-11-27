#include<bits/stdc++.h>
using namespace std;
const int N=12346;
using pii=pair<int,int>;
priority_queue<pii> q;
int dis[N];
bool vis[N];
vector<pii> g[N];
int x[N],y[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> x[i] >> y[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      g[i].push_back({j,max(abs(x[i]-x[j]),abs(y[i]-y[j]))});
      g[j].push_back({i,max(abs(x[i]-x[j]),abs(y[i]-y[j]))});
    }
  }
  int sum=0;
  q.push({dis[1],1});
  while(!q.empty()){
    int l=q.top().first;
    int x=q.top().second;
    q.pop();
    if(vis[x]==true) continue;
    vis[x]=true;
    sum+=l;
    for(auto e:g[x]){
      int xx=e.first;
      int ll=e.second;
      if(dis[xx]<ll && vis[xx]==false){
        dis[xx]=ll;
        q.push({dis[xx],xx});
      }
    }
   // cout << x << ' '<< dis[x] << "\n";
  }
  cout << sum;
}

