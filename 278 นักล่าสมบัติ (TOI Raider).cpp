#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int a[105][105];
int dp[5005][105][105];
int dx1[6]={0,0,1,1,-1,-1};
int dy1[6]={1,-1,0,-1,0,-1};
int dx2[6]={0,0,1,1,-1,-1};
int dy2[6]={1,-1,0,1,0,1};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> a[i][j];
    }
  }
  //q.push({{(n-1/2,0},0})
  //dp[1][(n-1)/2][0]=1;
  if(a[(n-1)/2][1]==1)   dp[1][(n-1)/2][1]=1;
  if(a[(n-1)/2+2][1]==1) dp[1][(n-1)/2+2][1]=1;
  if(a[(n-1)/2+1][1]==1) dp[1][(n-1)/2+1][1]=1;
  for(int k=1;k<=5000;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        
        if(dp[k][i][j]>0){
          if(i%2==0){
            for(int t=0;t<6;t++){
              int x=i+dx1[t];
              int y=j+dy1[t];
              if(a[x][y]!=0 && (k+1)%a[x][y]==0) dp[k+1][x][y]=1;
            }
          }
          else{
            for(int t=0;t<6;t++){
              int x=i+dx2[t];
              int y=j+dy2[t];
              if(a[x][y]!=0 && (k+1)%a[x][y]==0) dp[k+1][x][y]=1;
            }
          }
          
        }
      }
    }
    if(dp[k+1][(n-1)/2+1][m]==1){
      cout << k+1;
      return 0;
    } 
  }
}

