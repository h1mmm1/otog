#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=65;
vector<int> g[N];
bool vis[N];
int dis[N];
queue<int> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int m,s,n;
	cin >> m >> s >> n;
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++) dis[i]=1e6;
	q.push(s);
	dis[s]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		if(x==n){
			cout << dis[x];
			return 0;
		}
		for(auto e:g[x]){
			int xx=e;
			if(vis[xx]==false && dis[xx]>dis[x]+1){
				dis[xx]=dis[x]+1;
				q.push(xx);
			}
		}
	}
}
