#include<bits/stdc++.h>
using namespace std;
const int N=2e8+5;
int dp[N];

int dfs(int n,int l,int r){
  if(n<l+r) return 1;
  int sum=0;
  sum+=dfs(n*l/(l+r),l,r);
  sum+=dfs(n*r/(l+r),l,r);
  dp[n]+=sum;
  return sum;
}

int main(){
  ios::sync_with_stdio(); cin.tie(0);
  int n,l,r;
  cin >> n >> l >> r;
  cout << dfs(n,l,r);  
}
   
