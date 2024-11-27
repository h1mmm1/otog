#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=105;
ll X[N],Y[N];
bool chk[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> X[i] >> Y[i];
	}
//	cout << "\n";
	ll ans=0;
	for(int i=1;i<=m;i++){
		ll x,y,r,cnt=0;
		cin >> x >> y >> r;
		for(int j=1;j<=n;j++){
//			if(chk[j]) continue;
			if((X[j]-x)*(X[j]-x)+(Y[j]-y)*(Y[j]-y)<r*r){
				cnt++;
//				cout << (X[j]-x)*(X[j]-x)+(Y[j]-y)*(Y[j]-y) << ' ' << r*r << "\n";
//				cout << X[j] << ' ' << Y[j] << ' ' << x << ' '<< y << ' ' << r << "\n";
//				chk[j]=true;
			}
		}
		if(cnt!=0 && cnt!=n) ans++;
	}
	cout << ans;
}
