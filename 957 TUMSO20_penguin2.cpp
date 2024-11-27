#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MOD=998244353;

ll mod(ll n,ll m,ll MOD){
	ll ans=1;
	while(m>0){
		if(m%2==1){
			ans*=n;
			ans%=MOD;
		}
		n*=n;
		n%=MOD;
		m/=2;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		if(n==0){
			cout << "0\n";
		}
//		else 
		else{
			cout << (mod(2,n,MOD)-(n%MOD)+MOD)%MOD << "\n";
		}
	}
}
