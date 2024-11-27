#include<bits/stdc++.h>
using namespace std;
const int N=10000;
using ppi=pair<int,int>;
using pii=pair<ppi,char>;
vector<ppi> g[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
int dis[N];
bool vis[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<N;i++) dis[i]=1e9;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		char s,c;
		int b;
		cin >> s >> c >> b;
		int x=s-'A';
		int y=c-'A';
//		cout << x << ' ' << y << "\n";
		g[x].push_back({y,b});
		g[y].push_back({x,b});
		if(x<25){
			dis[x]=0;
			q.push({{dis[x],x},s});
		}
		if(y<25){
			dis[y]=0;
			q.push({{dis[y],y},c});
		}		
	}
	while(!q.empty()){
		int l=q.top().first.first;
		int x=q.top().first.second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		if(x=='Z'-'A'){
			cout << q.top().second << ' ' << l;
			return 0;
		}
		for(auto e:g[x]){
			int xx=e.first;
			int ll=e.second;
			if(vis[xx]==false && dis[xx]>dis[x]+ll){
				dis[xx]=dis[x]+ll;
				q.push({{dis[xx],xx},q.top().second});
			}
		}
	}
}
/*
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
*/

