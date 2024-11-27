#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using ppi=pair<int,int>;
using pii=pair<ll,ppi>;
const int N=2e5+5;
vector<pii> g[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
ll dis[15][N];
bool vis[15][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n-1;i++){
		int a,x,b;
		cin >> a >> x >> b;
		g[i].push_back({0,{i+1,a}});
		g[i].push_back({1,{x,b}});	
//		cout << i << ' ' << x << ' ' << a << ' ' << b << "\n";		
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<15;j++) dis[j][i]=1e18;
	}
	dis[0][0]=0;
	q.push({dis[0][0],{0,0}});
	while(!q.empty()){
		ll l=q.top().first;
		int t=q.top().second.first;
		int x=q.top().second.second;
		q.pop();
		if(vis[t][x]) continue;
		vis[t][x]=true;
//		cout << l << ' ' << t << ' ' << x << "\n";
		for(auto e:g[x]){
			int chk=e.first;
			int xx=e.second.first;
			int ll=e.second.second;
//			cout << chk << ' ' << xx << ' ' << ll <<"---\n";
			if(chk==1){
				if(t+1<=m && vis[t+1][xx]==false && dis[t+1][xx]>dis[t][x]+ll){
					dis[t+1][xx]=dis[t][x]+ll;
					q.push({dis[t+1][xx],{t+1,xx}});
				}
			}
			if(chk==0 && vis[t][xx]==false && dis[t][xx]>dis[t][x]+ll){
				dis[t][xx]=dis[t][x]+ll;
				q.push({dis[t][xx],{t,xx}});
			}				
			
		}
	}
	ll mn=1e18;
	for(int i=0;i<=m;i++){
		mn=min(dis[i][n-1],mn);
	}
	cout << mn;
//	cout << "\n";
//	for(int i=0;i<=m;i++){
//		for(int j=0;j<=n-1;j++){
//			if(dis[i][j]==1e18) cout << "- ";
//			else cout << dis[i][j] << " ";
//		}
//		cout << "\n";
//	}
}
