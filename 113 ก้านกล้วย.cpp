#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],dp[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=3;i<=n;i++){
    dp[i]=max(dp[i-1],dp[i-3]+a[i]);
  }
  cout << dp[n];
}   

