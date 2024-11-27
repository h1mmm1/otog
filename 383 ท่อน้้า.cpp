#include<bits/stdc++.h>
using namespace std;
int x[15005];
int y[15005];
bool vis[15005];
int dis[15005];
vector<int> a;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> x[i] >> y[i];
    dis[i]=INT_MAX;
  }
  int xx=1,sum=0;
  dis[xx]=0;
  for(int i=1;i<=n-1;i++){
    int mn=INT_MAX;
    int k;
    vis[xx]=true;
    for(int j=1;j<=n;j++){
      if(vis[j]==true) continue;
      int ll=abs(x[xx]-x[j])+abs(y[xx]-y[j]);
      if(ll<dis[j]){
        dis[j]=ll;
      }
      if(dis[j]<mn){
        mn=dis[j];
        k=j;
      }
    }
    xx=k;
    a.push_back(mn);
    sum+=mn;
  }
  sort(a.begin(),a.end());
  for(int i=a.size()-1;i>=0;i--){
    if(m>1) sum-=a[i],m--;
  }
  cout << sum;
}
