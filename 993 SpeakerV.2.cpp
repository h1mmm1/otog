#include<bits/stdc++.h>
using namespace std;
const int N=20;
int X[N],Y[N],n,dp[1<<N];
double ans=0;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);  
//  cin >> n;
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    scanf("%d%d",&X[i],&Y[i]);
  }
  for(int i=0;i<(1<<n);i++){
    int cnt=__builtin_popcount(i);
    if(cnt==3){
      vector<int> p;
      for(int j=0;j<n;j++){
        if((i&(1<<j))){
          p.push_back(j);
        }
      }
      dp[i]=abs(X[p[0]]*Y[p[1]]-X[p[1]]*Y[p[0]]+X[p[1]]*Y[p[2]]-X[p[2]]*Y[p[1]]+X[p[2]]*Y[p[0]]-X[p[0]]*Y[p[2]]);
    }
  }
  for(int i=1;i<(1<<n);i++){
    int cnt=__builtin_popcount(i);
    if(cnt>3 && cnt%3==0){
      for(int j=(i-1)&i;j>=1;j=(j-1)&i){
        int sum=__builtin_popcount(j);
        if(sum%3==0){
          dp[i]=max(dp[i],dp[j]+dp[i-j]);
        }
      }
    }
  }
  ans=double(dp[(1<<n)-1])/2;
//  cout << ans;
  printf("%.2lf",ans);
}

