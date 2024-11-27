#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e3+5,M=2e6+5;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
using pii=pair<int,int>;
queue<pii> q[3];
bool vis[N][N];
ll dp[M];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,kk,qq,ans=0;
  ll r=0,t=0;
  cin >> n >> m >> kk >> qq;
  for(int i=1;i<M;i++){
    t=0;
    int a,b;
    if(i<=kk){
      cin >> a >> b;
      a++;
      b++;   
      dp[i]++;

  }
//    cout << i << "\n";
    while(!q[i&1].empty()){
      int x=q[i&1].front().first;
      int y=q[i&1].front().second;
      q[i&1].pop();
//      cout << x << ' ' << y << "as" << '\n';
      for(int k=0;k<4;k++){
        int xx=x+dx[k];
        int yy=y+dy[k];
//        cout << k << '\n';
        if(xx<1 || yy<1 || xx>n || yy>m) continue;
        if(vis[xx][yy]==false){
          q[(i+1)&1].push({xx,yy});
          vis[xx][yy]=true;
          t++;
//          cout << xx << ' ' << yy << "\n";
        }
      }
    }
//    for(int i=1;i<=n;i++){
//      for(int j=1;j<=m;j++){
//        cout << vis[i][j] << ' ';
//    }
//    cout << "\n";
//  }
    dp[i]+=r+t+dp[i-1];
//    cout << r << ' ' << t << ' ' << dp[i] << "\n\n";  	
    if(vis[a][b]==false && i<=kk){
        q[(i+1)&1].push({a,b});
      vis[a][b]=true;
      r++;
    } 
    r=r+t;
  }
  while(qq--){
    int p;
    cin >> p;
    cout << dp[p] << "\n";
  }
}
/*
4 4 1 4
1 1
1
2
3
4

4 3 5 3
1 2
3 0
3 1
0 0
2 0
3
5
6


*/
