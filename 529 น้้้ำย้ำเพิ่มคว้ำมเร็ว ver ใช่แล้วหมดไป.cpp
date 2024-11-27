#include<bits/stdc++.h>
using namespace std;
using lll=long long int;
using ppi=pair<lll,lll>;
using ppp=pair<ppi,ppi>;
using pii=pair<ppp,lll>;
const int N=4e4+5;
vector<ppi> g[N];
int a[N];
lll dis[N][(1<<10)];
bool vis[N][(1<<10)];
priority_queue<pii,vector<pii>,greater<pii>> q;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lll n,m,p,k;
  cin >> n >> m >> p >> k;
  for(int i=1;i<=m;i++){
    lll aa,b,c;
    cin >> aa >> b >> c;
    g[aa].push_back({b,c});		
  }
  for(int i=1;i<=p;i++){
    lll x;
    cin >> x;
    a[x]|=(1<<i);
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<=(1<<(p+1));j++){
      dis[i][j]=1e18;
    }
  }

  if(a[1]>0 && k!=0){
    
    int st=0;
    for(int i=1;i<=p;i++){
      if((a[1]&(1<<i))!=0){
        st=(1<<i);
        dis[1][st]=0;
        break;
      }
    }
    q.push({{{dis[1][st],2},{1,st}},1});
  }
//  else{
    dis[1][0]=0;
    q.push({{{dis[1][0],1},{1,0}},-1});	    
//  }
	
  while(!q.empty()){
    lll l=q.top().first.first.first;
    lll sum=q.top().first.first.second;
    lll x=q.top().first.second.first;
    lll u=q.top().first.second.second;
    lll chk=q.top().second;
    q.pop();
    if(vis[x][u]) continue;
    vis[x][u]=true;
    if(x==n){
      cout << l;
      return 0;
    }
//    cout << x << "\n";
//		cout << l << ' ' << sum << ' ' << x << ' ' << t << ' ' << chk << "\n";
    
    for(auto e:g[x]){
      lll xx=e.first;
      lll ll=e.second;
      int t=u;
//      cout << xx << "---\n";
      if(a[xx]>0){       
        int st=__builtin_popcount(t);
        if(st+1<=k){
          if((a[xx]&t)!=a[xx]){
            for(int i=1;i<=p;i++){
              if(((a[xx]&(1<<i))!=0) && ((t&(1<<i))==0)){
                t|=(1<<i);
                break;
              }
            }
//            cout << xx << "--\n";
            if(vis[xx][t]==false && dis[xx][t]>dis[x][u]+ll/sum){
              dis[xx][t]=dis[x][u]+ll/sum;
//              cout << dis[xx][t] << ' ' << xx << ' ' << sum*2 << ' ' << t <<"\n";
              q.push({{{dis[xx][t],sum*2},{xx,t}},xx});        
            }    
          }

        }
      }
      if(vis[xx][u]==false && dis[xx][u]>dis[x][u]+ll/sum){
        dis[xx][u]=dis[x][u]+ll/sum;
//        cout << dis[xx][t] << ' ' << xx << ' ' << sum << ' ' << u <<"\n";        
        q.push({{{dis[xx][u],sum},{xx,u}},chk});
      }
    }
  }
}
