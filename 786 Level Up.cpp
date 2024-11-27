#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,mx=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
	}
	for(int j=1;j<=m;j++){
		int x,ans=0;
		cin >> x;
		if(x%mx!=0) ans++;
		ans+=x/mx; 
		cout << ans << "\n";
	}
}
