#include<bits/stdc++.h>
using namespace std;
const int N=12346;
using pii=pair<int,int>;
priority_queue<pii> q;
int dis[N];
bool vis[N];
vector<pii> g[N];
int X[N],Y[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> X[i] >> Y[i];
  }
  int x=1,id,ans=0;
  for(int i=1;i<=n-1;i++){
    int ll=0,mx=0;
    if(vis[x]==true) continue;
    vis[x]=true;
    for(int j=1;j<=n;j++){
      if(vis[j]==false){
        ll=max(abs(X[x]-X[j]),abs(Y[x]-Y[j]));
        if(dis[j]<ll){
          dis[j]=ll;
        }
        if(dis[j]>mx){
          mx=dis[j];
          id=j;          
        }
      }
    }
    ans+=mx;
    x=id;
  } 

  cout << ans;
}

