#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e6+5;
ll a[N],mp1[N],mp2[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n,ans=0;
	scanf("%d",&n);
	for(ll i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(mp1[a[i]]==0) mp1[a[i]]=i;
		mp2[a[i]]=i;
	}
	for(ll i=1;i<=2000;i++){
		for(ll j=1;j<=2000;j++){
			if(mp1[i]==0|| mp1[j]==0) continue;
			if(ans<1ll*min(i,j)*max(abs(mp2[i]-mp1[j]),abs(mp2[j]-mp1[i]))){
				ans=1ll*min(i,j)*max(abs(mp2[i]-mp1[j]),abs(mp2[j]-mp1[i]));
//				cout << i << ' ' << j << ' ' << ans << '\n';
			}
//			ans=max(ans,);
		}
	}
//	for(int i=1;i<=n;i++){
//		cout << mp1[a[i]] << ' ';
//	}
//	cout << "\n";
//	for(int i=1;i<=n;i++){
//		cout << mp2[a[i]] << ' ';
//	}
//	cout << "\n";	
	printf("%d",ans);
}

