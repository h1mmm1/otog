#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<int,string>;
set<ll> s;

inline ll rec(string cnt){
	ll x=0,sum=1,n=cnt.size();
	for(int i=n-1;i>=0;i--){
		x+=(cnt[i]-'0')*sum;
		sum*=10;
	}
	return x;
}

int main(){
  ios::sync_with_stdio(0); cin. tie(0);
  int n;
  string str;
  cin >> n >> str;
  for(int i=0;i<(1<<n);i++){
    string cnt;
    for(int j=0;j<n;j++){
      
      if((i&(1<<j))==0){
        cnt+=str[j];
      }
    }
    ll x=rec(cnt);
    s.insert(-x);
  }
  for(auto e:s){
    
    cout << -e << "\n";
  }
}

