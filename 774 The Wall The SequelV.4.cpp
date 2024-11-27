#include<bits/stdc++.h>
using namespace std;
int a[100005];
int dp[101][100005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    dp[1][i]+=a[i]+dp[1][i-1];
    
  }
  for(int k=2;k<=min(100,n);k++){
    for(int j=1;j<k;j++){
      dp[k][j]=a[j];
    }
    for(int i=k;i<=n;i++){
      dp[k][i]+=a[i]+dp[k][i-k];
    }
  }
  
  
  while(m--){
    int l,m,r,sum=0;
    scanf("%d%d%d",&l,&m,&r);
    if(m==1) sum+=dp[1][r]-dp[1][l-1];
    else if(m<=100){
      r-=(r-l)%m;      
      sum+=dp[m][r];
      if(l>m-1) sum-=dp[m][l-m];
    }
    else{
      for(int i=l;i<=r;i+=m){
        sum+=a[i];
      }
    }
    printf("%d ",sum);
  }
}

