#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<int> g[N];
int cnt=0,ans=0,dis[N],low[N];

inline void rec(int x,int p){
	cnt++;
	dis[x]=low[x]=cnt;
	for(auto e:g[x]){
		if(e==p) continue;
		if(dis[e]==0){
			rec(e,x);
			low[x]=min(low[x],low[e]);
		}
		else{
			low[x]=min(low[x],dis[e]);
		}
	}
	if(dis[x]==low[x]) ans++;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	rec(1,1);
	cout << ans;
}
