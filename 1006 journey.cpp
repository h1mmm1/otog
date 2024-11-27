#include<bits/stdc++.h>
using namespace std;
const int N=25;
int a[N][N],n;
bool vis[N];
int dis[2000][N],mx=-1e9;

inline void rec(int l,int st,int x){
//	cout << l << ' ' << st << ' ' << x << "\n";
	if(x==n){
		mx=max(mx,l);
		return;
	}
	for(int e=1;e<=n;e++){
		if(vis[e] || e==x) continue;
		vis[e]=true;
		rec(l+a[x][e],st+1,e);
		vis[e]=false;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	vis[1]=true;
	rec(0,1,1);
	cout << mx;
}
