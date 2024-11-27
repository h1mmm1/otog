#include<bits/stdc++.h>
using namespace std;
using lll=long long int;
using ppi=pair<lll,lll>;
using ppp=pair<ppi,ppi>;
using pii=pair<ppp,lll>;
const int N=8e4+5;
vector<ppi> g[N];
bool a[N];
lll dis[N][10];
bool vis[N][10];
priority_queue<pii,vector<pii>,greater<pii>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	lll n,m,p,k;
	cin >> n >> m >> p >> k;
	for(int i=1;i<=m;i++){
		lll aa,b,c;
		cin >> aa >> b >> c;
		g[aa].push_back({b,c});		
	}
	for(int i=1;i<=p;i++){
		lll x;
		cin >> x;
		a[x]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<10;j++){
			dis[i][j]=1e18;
		}
	}

	if(a[1]==true){
		dis[1][1]=0;
		q.push({{{dis[1][1],2},{1,1}},1});
	}
	dis[1][0]=0;
	q.push({{{dis[1][0],1},{1,0}},-1});		
	while(!q.empty()){
		lll l=q.top().first.first.first;
		lll sum=q.top().first.first.second;
		lll x=q.top().first.second.first;
		lll t=q.top().first.second.second;
		lll chk=q.top().second;
		q.pop();
		if(vis[x][t]) continue;
		vis[x][t]=true;
		if(x==n){
			cout << l;
			return 0;
		}
//		cout << l << ' ' << sum << ' ' << x << ' ' << t << ' ' << chk << "\n";
		for(auto e:g[x]){
			lll xx=e.first;
			lll ll=e.second;
			if(a[xx]==true){
				if(vis[xx][t+1]==false && dis[xx][t+1]>dis[x][t]+ll/sum && t+1<=k && chk!=xx){
					dis[xx][t+1]=dis[x][t]+ll/sum;
					q.push({{{dis[xx][t+1],sum*2},{xx,t+1}},xx});
				}
			}
			if(vis[xx][t]==false && dis[xx][t]>dis[x][t]+ll/sum){
				dis[xx][t]=dis[x][t]+ll/sum;
				q.push({{{dis[xx][t],sum},{xx,t}},chk});
			}
		}
	}
}
