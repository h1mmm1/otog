#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while(q--){
    vector<int> p;
    int n,ans=0;
    cin >> n;
    for(int i=1;i<n;i++){
      if(__gcd(i,n)==1) {
        ans++;
        p.push_back(i);
      }
    }
    cout << ans << "\n";
    for(int e:p){
      cout << e << ' ';
    }
    cout << "\n";
}
}
