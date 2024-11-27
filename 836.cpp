#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long int t;
	cin >> t;
	while(t--){
		long long int n;
		cin >> n;
		if(n==2 || n==1) cout << "NO\n";
		else cout << (n-3)%MOD << "\n";
	}
}
