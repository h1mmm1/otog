#include<bits/stdc++.h>
using namespace std;
using lll=long long int;
using pii=pair<int,int>;
const int N=105;
vector<pii> g[N];
int vis[N];
lll dis[N];
queue<pii> q;
bool chk[N],ok[N][N];

inline void rec(int x,int p){
//	cout << x << ' ' << p << "\n";
  vis[x]=1;
  for(auto e:g[x]){
    int xx=e.first;
    int ll=e.second;
    if(xx==p || vis[xx]==2) continue;
    if(vis[xx]==1){
      cout << "YES";
      exit(0);
    }
    rec(xx,x);
  }
  vis[x]=2;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=1;i<=m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
    if(ok[u][v]){
    	cout << "YES";
    	return 0;
	}
	ok[u][v]=ok[v][u]=true;
  }
  for(int i=1;i<=n;i++) if(vis[i]==0) rec(i,-1);
  lll mx=0;
  for(int i=1;i<=n;i++){
  	  for(int j=1;j<=n;j++) dis[j]=0,chk[j]=false;
  	  dis[i]=0;
  	  chk[i]=true;
//    if(dis[i]==0){
      q.push({dis[i],i});
      while(!q.empty()){
        int l=q.front().first;
        int x=q.front().second;
        q.pop();
        mx=max(mx,dis[x]);
//        cout << l << ' ' << x << ' ' << mx << "\n";
        for(auto e:g[x]){
          int xx=e.first;
          int ll=e.second;
          if(chk[xx]) continue;
          if(dis[xx]<dis[x]+ll){
          	  chk[xx]=true;
	          dis[xx]=dis[x]+ll;
	          q.push({dis[xx],xx});          	
		  }
        }
      }

//      memset(chk,false,sizeof chk);
//    }
  }
//  cout << mx << "\n";
  if(mx>=k) cout << "YES";
  else cout << "NO";
}
