#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int a[100005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  ll l=0,r=1e18;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  
  while(l<r){
    ll mid=(l+r)/2;
    ll sum=0;
    for(int i=1;i<=n;i++){
      sum+=mid/a[i];
      if(sum>m) break;
    }
    if(sum<m){
      l=mid+1;
    }
    else{
      r=mid;
    }
  }
  cout << l;
}
