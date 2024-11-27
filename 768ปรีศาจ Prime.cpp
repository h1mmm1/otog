#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  if(n<=1){
  	cout << "No";
  	return 0;
  }
  for(int i=2;i<=sqrt(n);i++){
  	if(n%i==0){
  		cout << "No";
  		return 0;
	  }
  }
  cout << "Yes";

}
