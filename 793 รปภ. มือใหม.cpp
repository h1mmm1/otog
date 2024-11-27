#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	while(k--){
		int x,y;
		cin >> x >> y;
		cout << a[x+1][y+1] << '\n';
	}
}
