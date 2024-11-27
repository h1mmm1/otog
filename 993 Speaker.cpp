#include<bits/stdc++.h>
using namespace std;
const int N=20;
int X[N],Y[N],n;
double ans=0;
vector<int> g[10];

inline void rec(int cnt){
  if(cnt==n+1){
    double sum=0;
    for(int i=1;i<=n/3;i++){
      // for(int j=0;j<g[i].size();j++){
      sum+=abs(X[g[i][0]]*Y[g[i][1]]-X[g[i][1]]*Y[g[i][0]]+X[g[i][1]]*Y[g[i][2]]-X[g[i][2]]*Y[g[i][1]]+X[g[i][2]]*Y[g[i][0]]-X[g[i][0]]*Y[g[i][2]]);
      // }
    }
    ans=max(ans,sum/2);
    return;
  }
  for(int i=1;i<=n/3;i++){
    if(g[i].size()<3){
      g[i].push_back(cnt);
      rec(cnt+1);
      g[i].pop_back();      
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);  
//  cin >> n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
//    cin >> X[i] >> Y[i];
    scanf("%d%d",&X[i],&Y[i]);
  }
  g[1].push_back(1);
  rec(2);
  printf("%.2lf",ans);
//  cout << ans;
}
