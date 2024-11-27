#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int a[1505][1505];// /;
int b[1505][1505];// \;
ll x[90005];
ll ix[90005];
ll mod(ll n,ll m,ll x){
	ll ans=1;
	while(m>0){
		if(m%2==1){
			ans*=n;
			ans%=x;
		}
		n*=n;
		n%=x;
		m/=2;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int y=1e6+3;
	x[0]=1;
	ix[0]=1;
	for(int i=1;i<=90001;i++){
		x[i]=(i*x[i-1])%y;
		ix[i]=mod(x[i],y-2,y);
	}
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin >> c;
			if(c=='#'){
				a[i+600][j+600]++;
				b[i+600][j+600]++;
			}
		}
	}
	for(int i=1;i<=1500;i++){
		for(int j=1;j<=1500;j++){
			a[i][j]+=a[i-1][j+1];
			b[i][j]+=b[i-1][j-1];
		}
	}
	ll ans=0;
	for(int r=1;r<=n+m;r++){
		for(int i=601;i<=600+n;i++){
			for(int j=601;j<=600+m;j++){
				ll cnt=0;
				cnt+=a[i][j-r]-a[i-r-1][j+1];
				cnt+=a[i+r][j]-a[i-1][j+r+1];
				cnt+=b[i+r-1][j-1]-b[i][j-r];
				cnt+=b[i-1][j+r-1]-b[i-r][j];
				if(cnt>=k){
					ans+=(((x[cnt]*ix[cnt-k])%y)*ix[k])%y;
					ans%=y;
				}
				//cout << cnt << ' ';
			}
		}
	}
	cout << ans;
	/*
	for(int i=1;i<=10;i++){
		cout << x[i] << ' ' << ix[i] << '\n';
	}
	*/
}
