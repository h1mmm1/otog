#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=105,MOD=5454541;
ll a[N],dp[N][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  scanf("%lld",&n);
  ll ans=n;
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
  }
  for(int L=2;L<=n;L++){
    dp[0][0]=1;
    for(int i=1;i<=n;i++){		
      int tmp=a[i]%L;
      int mn=min(L,i);
      for(int j=mn;j>0;j--){
        for(int k=0;k<L;k++){
          dp[j][k]+=dp[j-1][(k-tmp+L)%L];
          dp[j][k]%=MOD;
        }
      }
    }
    ans+=dp[L][0];
    ans%=MOD;
    memset(dp,0,sizeof dp);
  }
  printf("%lld",ans);
}


