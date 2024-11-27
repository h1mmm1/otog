#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5,M=25,mod=1e9+7;
int a[M][N];
ll f[N],ff[N];

inline ll MOD(ll n,ll m){
	ll ans=1;
	while(m>0){
		if(m%2==1){
			ans*=n;
			ans%=mod;
		}
		n*=n;
		n%=mod;
		m/=2;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;	
	f[0]=1,ff[0]=1;
	for(int i=1;i<N;i++){
		f[i]=f[i-1]*i;
		f[i]%=mod;
		ff[i]=MOD(f[i],mod-2);
	}
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		a[x][i]++;
	}
	for(int i=0;i<M;i++){
		for(int j=1;j<=n;j++){
			a[i][j]+=a[i][j-1];
		}
	}
//	for(int i=1;i<=20;i++){
//		cout << ff[i] << ' ';
//	}
//	for(int i=1;i<=10;i++){
//		for(int j=1;j<=n;j++){
//			cout << a[i][j] << ' ';
//		}
//		cout << "\n";
//	}
	while(k--){
		int l,r,p;
		cin >> l >> r >> p;
		l++,r++;
		ll cnt=a[p][r]-a[p][l-1];
//		cout << cnt << " " << m << ' ';
		if(cnt<m) cout << "-1\n";
		else cout << ((f[cnt]*ff[m])%mod*ff[cnt-m])%mod << "\n";
	}
}
