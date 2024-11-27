#include <bits/stdc++.h>
#include "function.h"
using namespace std;
using ll=long long int;
using pii=pair<ll,int>;
const int N=5e5+5;
ll dp[22][N],sum1[N],sum2[N],a[N];

ll call(int i,int j){
  ll cnt1,cnt2;
  if(j==0) cnt1=0,cnt2=0;
  else cnt1=sum1[j-1],cnt2=sum2[j-1];  
  return ((sum1[i]-cnt1)*(sum1[i]-cnt1)+(sum2[i]-cnt2))/2;
}

void compute(int k,int l,int r,int optl,int optr){
  if(l>r) return;
  int mid=(l+r)/2;
  pii best={1e18,-1};
  for(int i=optl;i<=min(optr,mid);i++){
    best=min(best,{(i ? dp[k-1][i-1] : 0)+call(mid,i),i});
  }
  dp[k][mid]=best.first;
  int opt=best.second;
  compute(k,l,mid-1,optl,opt);
  compute(k,mid+1,r,opt,optr);  
}

long long minPenguinValue(int n, int m, std::vector<int> a){
	sum1[0]=a[0];
	sum2[0]=a[0]*a[0];
  for(int i=1;i<n;i++){
    sum1[i]=sum1[i-1]+a[i];
    sum2[i]=sum2[i-1]+a[i]*a[i];
  }

  for(int i=0;i<n;i++){
    dp[0][i]=call(i,0);
  }
  for(int k=1;k<m;k++){
    compute(k,0,n-1,0,n-1);
  }
//  for(int k=0;k<m;k++){
//    for(int i=0;i<n;i++){
//    	cout << dp[k][i] << ' ';
//	}
//	cout << "\n";
//  }  
   return dp[m-1][n-1];
}
/*
5 3
1 2 3 4 5
*/
