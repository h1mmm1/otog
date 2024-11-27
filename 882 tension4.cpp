// https://cp-algorithms.com/algebra/divisors.html
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n,q;
  cin >> n >> q;
  while(q--){
    ll l,r;
    cin >> l >> r;
    ll cntl=0,cntr=0,sum=1;
    for(int i=1;sum<=r;i++){
      cntr+=(sqrt(r/sum)+1)/2;
      sum*=2;
    }
    sum=1;
    for(int i=1;sum<=l-1;i++){
      cntl+=(sqrt((l-1)/sum)+1)/2;
      sum*=2;
    }
    cout << cntr-cntl << "\n";
  }
}
