#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int dp[500005];
bool b[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i=2;i*i<N;i++){
    if(b[i]==false){
      for(int j=i*i;j<N;j+=i){
        b[j]=true;
      }
    }
  }
  b[0]=true;
  b[1]=true;
  int n,k,x,mn=INT_MAX,u;
  cin >> n >> k;
  for(int i=1;i<=n;i++){
    int m;
    cin >> m;
    if(b[m]==false){
      dp[i]++;
      
    }
    dp[i]+=dp[i-1];
  }
  for(int i=1;i<=n;i++){
    if(dp[i]>=k){
      x=dp[i]-k+1;
      auto v=lower_bound(dp+1,dp+1+n,x)-dp;
      u=v;
      mn=min(mn,i-u+1);
    }
    
  }
  cout << mn;
  //for(int i=1;i<=10;i++)cout << b[i];
}
