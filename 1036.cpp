#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=2e5+5;
ll a[N],b[N],sum[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		if(i%2==1){
			a[i]=x;
		}
		else b[i]=x;
		a[i]+=a[i-1];
		b[i]+=b[i-1];
		sum[i]=sum[i-1]+x;
	}
	while(m--){
		int l,r;
		cin >> l >> r;
		if(l%2==1){
			cout << sum[r]-sum[l-1]-(b[r]-b[l-1])*2 << "\n";
		}
		else if(l%2==0){
			cout << sum[r]-sum[l-1]-(a[r]-a[l-1])*2 << "\n";
		}
//		else if(r%2==0 && l%2==1){
//			cout << sum[r]-sum[l-1]-(b[r]-b[l-1])*2 << "\n";
//		}
//		else{
//			cout << sum[r]-sum[l-1]-(a[r]-a[l-1])*2 << "\n";
//		}
	}
}
