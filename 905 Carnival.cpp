#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],n,mx=0;

inline void rec(int x,int cnt,int u,int v){
//	cout << x << ' ' << cnt << ' ' << u << ' ' << v << "\n";
	if(x==n){
		mx=max(mx,cnt);
		return;
	}
	for(int i=1;i<=n-x+1;i++){
		if((u<=i && i<=v) || (u<=i+x-1 && i+x-1<=v)){
			rec(x+1,cnt+(a[i+x-1]-a[i-1])/2,i,i+x-1);
		}
		else rec(x+1,cnt+(a[i+x-1]-a[i-1]),i,i+x-1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	rec(1,0,-1,-1);
	cout << mx+a[n]/2;
}
