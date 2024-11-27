#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using piii=pair<int,pii>;
priority_queue<piii,vector<piii>,greater<piii>> q;
int a[20][20];
int dp[20][20];
int dx[3]={1,0,-1};
int e[20][20];
stack<int> aa;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
  cin >> n >> m >> k;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      cin >> a[i][j];
      dp[i][j]=INT_MAX;
    }
  }
  dp[k][1]=a[k][1];
  q.push({a[k][1],{k,1}});
  while(!q.empty()){
    int l=q.top().first;
    int x=q.top().second.first;
    int y=q.top().second.second;
    q.pop();
    if(y==n) continue;
    if(x==1){
      for(int i=1;i<3;i++){
        int xx=x+dx[i];
       if(dp[xx][y+1]>dp[x][y]+a[xx][y+1]){
          dp[xx][y+1]=dp[x][y]+a[xx][y+1];
         q.push({dp[xx][y+1],{xx,y+1}});
         e[xx][y+1]=x;
        }        
      }      
    }
    else if(x==m){
      for(int i=0;i<2;i++){
        int xx=x+dx[i];
       if(dp[xx][y+1]>dp[x][y]+a[xx][y+1]){
          dp[xx][y+1]=dp[x][y]+a[xx][y+1];
         q.push({dp[xx][y+1],{xx,y+1}});
         e[xx][y+1]=x;
        }        
      }      
    }
    else{
      for(int i=0;i<3;i++){
        int xx=x+dx[i];
       if(dp[xx][y+1]>dp[x][y]+a[xx][y+1]){
          dp[xx][y+1]=dp[x][y]+a[xx][y+1];
         q.push({dp[xx][y+1],{xx,y+1}});
         e[xx][y+1]=x;
        }        
      }
    }
  }
  int ans=INT_MAX,x;
  for(int i=1;i<=m;i++){
    if(ans>dp[i][n]){
      ans=dp[i][n];
      x=i;
    }  
  }
  cout << ans <<"\n";
  
  while(n!=0){
  	int xx=a[x][n];
  	aa.push(xx);
    //cout << xx << ' ';
    x=e[x][n];    
    n-=1;

  }
  while(!aa.empty()){
  	cout << aa.top() << ' ';
  	aa.pop();
  }
  /*
 
  for(int i=1;i<=n;i++){
  	for(int j=1;j<=m;j++){
  		cout << dp[i][j] << ' ';
	  }
	  cout << "\n";
  }
  */
}

