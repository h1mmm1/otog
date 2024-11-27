#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e6+5;
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	ll l=0,r=1e18;
	while(l<r){
		ll mid=(l+r)/2;
		ll cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i]/mid;
		}
		if(cnt<m){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	ll x=l-1,ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i]/x;
	}
	if(ans==m){
		cout << "YES\n";
	}
	else cout << "NO\n";
	cout << x;
}
