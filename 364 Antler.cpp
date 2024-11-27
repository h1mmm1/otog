#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,mx=0,ans=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		a[x]++;
		mx=max(x,mx);
	}
	for(int i=2;i<=mx;i++){
		int cnt=0;
		for(int j=i;j<=mx;j+=i) cnt+=a[j];
		if(cnt>1) ans=max(ans,cnt*i); 
	}
	cout << ans;
}

