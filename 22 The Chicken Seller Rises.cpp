#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char a[N][N];
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
queue<pair<int,int>> q;
int vis[N][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      vis[i][j]=INT_MAX;
    }
  }
  int x,y,tp1,tp2;
  cin >> x >> y >> tp1 >> tp2;
  bool chk=true;
  q.push({x,y});
  vis[x][y]=0;
  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    if(x==tp1 && y==tp2){
      cout << vis[x][y];
      chk=false;
      break;
    }
    for(int k=0;k<8;k++){
      int xx=x+dx[k];
      int yy=y+dy[k];
      if(vis[xx][yy]>vis[x][y]+1 && a[xx][yy]=='.'){
        vis[xx][yy]=vis[x][y]+1;
        q.push({xx,yy});
      }
    }
  }
  if(chk==true) cout << "-1";
}

