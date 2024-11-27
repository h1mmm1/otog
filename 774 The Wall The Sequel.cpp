#include<bits/stdc++.h>
using namespace std;
int a[100005];
int dp[100005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    dp[i]+=a[i]+dp[i-1];
  }
  while(m--){
    int l,m,r,sum=0;
    scanf("%d%d%d",&l,&m,&r);
    if(m==1) sum+=dp[r]-dp[l-1];
    else{
      for(int i=l;i<=r;i+=m){
        sum+=a[i];
      }
    }
    printf("%d ",sum);
  }
}

