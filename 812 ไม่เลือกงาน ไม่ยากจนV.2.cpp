#include<bits/stdc++.h>
using namespace std;
const int N=25;
int a[N][N],n,mn=INT_MAX;
bool vis[N];
int dp[1<<N];

int rec(int cnt,int st){
  if(cnt==n){
    return 0;
  }
  if(dp[st]!=INT_MAX) return dp[st];
  int ans=INT_MAX;

  for(int i=0;i<n;i++){
    if((st&(1<<(i)))!=0) continue;
    int x=a[cnt][i]+rec(cnt+1,st|(1<<(i)));
    ans=min(ans,x);
//    cout << x << "\n";
  }
  dp[st]=ans;
  return dp[st];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  } 
  for(int i=0;i<(1<<N);i++) dp[i]=INT_MAX;
  cout << rec(0,0);
}


