#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e6+5;
ll a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n,m,mn=LLONG_MAX,l=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
		while(l<=i && a[i]-a[l]>=m){
			mn=min(mn,i-l);
			l++;
		}
	}
	cout << mn;
}
