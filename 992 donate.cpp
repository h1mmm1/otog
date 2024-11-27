#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5;
int a[N],qs[20][N];
ll dp[20][N],dp2[20][N];
vector<int> g[N];
int n,m;

inline ll rec(int st,int x,int p){
	if(dp[st][x]!=-1e9) return dp[st][x];
	ll cnt=0;
	for(auto e:g[x]){
		if(p==e) continue;
		cnt+=max(rec(st+1,e,x)+qs[st+1][e],rec(st,e,x)+qs[st][e]-m);
	}
	return dp[st][x]=cnt;
}

inline ll dfs(int st,int x,int p){
	if(dp2[st][x]!=-1e9) return dp2[st][x];
	ll cnt=0;
	for(auto e:g[x]){
		if(p==e) continue;
		cnt+=max(dfs(st+1,e,x)+qs[st+1][e],dfs(st,e,x)+qs[st][e]-m);
	}
	return dp2[st][x]=cnt;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i],qs[0][i]=a[i];
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<=10;i++){
		for(int j=0;j<=n;j++){
			dp2[i][j]=dp[i][j]=-1e9;
		}
	}	
	for(int i=0;i<=n;i++){
		for(int j=1;j<=11;j++){
			qs[j][i]=qs[j-1][i]/3;
		}
	}
	cout << max(rec(0,0,-1)+a[0]-m,dfs(1,0,-1)+a[0]/3);
//	cout << "\n";
//	for(int i=0;i<=10;i++){
//		for(int j=0;j<=n;j++){
//			cout << qs[i][j] << ' ';
//		}
//		cout << "\n";
//	}

}
