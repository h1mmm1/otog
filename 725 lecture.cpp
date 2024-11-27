#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5,M=305;
ll dp[N],g[M][M],a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int c,n,m;
	cin >> c >> n >> m;
	for(int i=1;i<=c;i++){
		cin >> a[i];
	}
	for(int i=1;i<=c;i++){
		cin >> dp[i];
		dp[i]+=dp[i-1];
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			g[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++){
		ll aa,b,c;
		cin >> aa >> b >> c;
		g[aa][b]=g[b][aa]=min(g[aa][b],c);
	}
	for(int k=1;k<M;k++){
		for(int i=1;i<M;i++){
			for(int j=1;j<M;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	ll l=0,r=1e9;
	int rr=0;
	if(c>1000) rr=1;
	while(l<r){
		ll mid=(l+r)/2,cnt=0;
		bool chk=true;
		for(int i=2;i<=c;i++){
			ll v=a[i],u=a[i-1];
			ll w=g[v][u]*mid;
			cnt=max(cnt,dp[i-1]-w)+w;
			if(cnt+rr>dp[i]){
				chk=false;
				break;
			}
		}
//		cout << mid << "\n";
		if(chk) l=mid+1;
		else r=mid;
	}
	cout << l-1;
}
/*
5 5 4
3 1 4 1 5
92 65 35 89 79
1 2 3
2 3 4
3 4 5
4 5 6

*/
