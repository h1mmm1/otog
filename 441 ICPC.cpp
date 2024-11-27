#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll a[45];

inline char rec(ll n,ll i){
	if(i==0) return 'P';
	else if(n==a[i-1]+1) return 'P';
	else if(n<=a[i-1]) return rec(n,i-1);
	else if(n>2*a[i-1]+1) return rec(n-2*(a[i-1])-1,i-1);
	else if(rec(n-a[i-1]-1,i-1)=='A') return 'P';
	return 'A';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	a[0]=1;
	for(int i=1;i<=39;i++){
		a[i]=a[i-1]*3+1;
	}
	for(int i=1;i<=n;i++){
		ll m;
		cin >> m;
		cout << rec(m,39) << "\n";
	}
}
