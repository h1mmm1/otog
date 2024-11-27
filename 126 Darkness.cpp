#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=1e4+5,M=2e3+5;
priority_queue<pii,vector<pii>,greater<pii>> q;
bool vis[N];
int dis[N];
vector<pii> p;
vector<pii> g[M];
char s[M];

int main(){
//  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,k,st1,st2,tp1,tp2;
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=n;i++){
    scanf("%s",s);
    for(int j=1;j<=m;j++){
      char c=s[j-1];
      if(c=='X') p.push_back({i,j});
      else if(c=='A') st1=i,st2=j;
      else if(c=='B') tp1=i,tp2=j;
    }
  }
  if(abs(st1-tp1)+abs(st2-tp2)<=k){
    printf("%d",abs(st1-tp1)+abs(st2-tp2));
    return 0;
  }
  int w=p.size();
  for(int i=0;i<w;i++){
    for(int j=i+1;j<w;j++){
      int r=abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
      if(r<=k){
        g[i].push_back({j,r});
        g[j].push_back({i,r});
      }
    }
  }
  for(int i=0;i<w;i++){
    int r=abs(p[i].first-st1)+abs(p[i].second-st2);
    if(r<=k) g[w].push_back({i,r});
  }
  for(int i=0;i<w;i++){
    dis[i]=INT_MAX;
    int r=abs(p[i].first-tp1)+abs(p[i].second-tp2);
    if(r<=k) g[i].push_back({w+1,r});
  }
  dis[w+1]=INT_MAX;
  dis[w]=0;
  q.push({dis[w],w});
  while(!q.empty()){
    int l=q.top().first;
    int x=q.top().second;
    q.pop();
    if(vis[x]) continue;
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
  if(dis[w+1]!=INT_MAX) printf("%d",dis[w+1]);
  else printf("-1");

}

