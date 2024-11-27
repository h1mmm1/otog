#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e4+5;
ll a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	ll l=1e18,r=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		l=min(a[i],l);
		r+=a[i];
	}
	ll xx=0,y=r;
	while(m--){
		ll x;
		cin >> x;
		l=xx,r=y;
		while(l<r){
			ll mid=(l+r)/2,sum=0,cnt=0;
			bool chk=true;
			for(int i=1;i<=n;i++){
				sum+=a[i];
				if(sum>=mid){
					sum=0;
					cnt++;
				}
			}
			if(sum!=0) cnt++;
			if(cnt>x) l=mid+1;
			else r=mid;
//			cout << mid << ' ' << cnt << "\n";
		}		
		cout << r << "\n";
	}

}
/*
10

7 9 15 24 27
7 2 6 9 3

8   8     8
9 7 6 4 2 5
9 16 22 26 28 33
*/
