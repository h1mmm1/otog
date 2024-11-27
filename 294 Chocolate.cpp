#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll a,b,ans=0;
	cin >> a >> b;
	ans+=a-1;
	ans+=(b-1)*a;
	cout << ans;
}
