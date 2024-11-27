#include<bits/stdc++.h>
using namespace std;
int a[105];
int dp[105];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    a[i]=i;
  }
  dp[0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(j-a[i]>=0) dp[j]+=dp[j-a[i]];
    }
  }
  cout << dp[n];
}
