#include<bits/stdc++.h>
using namespace std;
int a[1205][1205];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,b,k,q;
	cin >> n >> m >> b >> k >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	while(b--){
		int x,y;
		cin >> x >> y;
		x++;
		y++;
		a[x][y]++;
		for(int i=max(0,x-k);i<=x+k;i++){
			a[i][y]--;
			if(a[i][y]<0) a[i][y]=0;
		}
		for(int j=max(0,y-k);j<=y+k;j++){
			a[x][j]--;
			if(a[x][j]<0) a[x][j]=0;
		}
	}
	while(q--){
		int v,u;
		cin >> v >> u;
		v++;
		u++;
		cout << a[v][u] << "\n";
	}
//	cout << "\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout << a[i][j] << ' ';
//		}
//		cout << "\n";
//	}
}
