#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e6+5;
ll a[N];

int main(){
	ll n,m;
	ll mn=LLONG_MAX;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll l=0,sum=0;
	for(int r=1;r<=n;r++){
		sum+=a[r];
		while(sum>=m){
			mn=min(mn,r-l+1);
			sum-=a[l++];			
//			cout << l << ‘ ‘ << r << ‘\n’;
		}
		
	}
	printf("%lld",mn);
}
