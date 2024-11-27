#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=5e5+5;
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
		ll mid=(l+r)/2,cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i]/mid;
			if(a[i]%mid!=0) cnt++;
		}
		if(cnt>m){
			l=mid+1;	
		}
		else{
			r=mid;
		}
	}
	cout << l;
}
