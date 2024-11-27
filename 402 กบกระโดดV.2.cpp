#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<int,int>;
using piii=pair<int,pii>;
ll a[20][20];
ll dp[20][20];
int dx[3]={1,0,-1};
int e[20][20];
stack<int> aa;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,k;
  cin >> m >> n >> k;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      cin >> a[i][j];
      dp[i][j]=LLONG_MAX;
    }
  }
  dp[k][1]=a[k][1];
  for(int j=1;j<=n;j++){
    for(int i=2;i<m;i++){
      if(dp[i][j]!=LLONG_MAX){
        for(int k=0;k<3;k++){
          int x=i+dx[k];
          if(dp[x][j+1]>dp[i][j]+a[x][j+1]){
            dp[x][j+1]=dp[i][j]+a[x][j+1];
            e[x][j+1]=i;
          }
        }
      }
    }
    if(dp[1][j]!=LLONG_MAX){
      for(int k=0;k<2;k++){
        int x=1+dx[k];
        if(dp[x][j+1]>dp[1][j]+a[x][j+1]){
           dp[x][j+1]=dp[1][j]+a[x][j+1];
           e[x][j+1]=1;
        }
        
      }
    }
    if(dp[m][j]!=LLONG_MAX){
      for(int k=1;k<3;k++){
        int x=m+dx[k];
        if(dp[x][j+1]>dp[m][j]+a[x][j+1]){
          dp[x][j+1]=dp[m][j]+a[x][j+1];
          e[x][j+1]=m;
          
        }        
      }
    }
  }
  ll mn=LLONG_MAX,id;
  for(int i=1;i<=m;i++){
    if(dp[i][n]<mn){
      mn=dp[i][n];
      id=i;
    }
  }
  cout << mn << "\n";
  while(n!=0){
    aa.push(a[id][n]);
    id=e[id][n];
    n--;   
  }
  while(!aa.empty()){
    cout << aa.top() << ' ';
    aa.pop();
  }
}


