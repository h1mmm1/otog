#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int> g[N];
int dis[N],dis2[N];
bool vis[N],vis2[N];
queue<pair<int,int>> q;

inline void rec(int x,int p){
	vis2[x]=true;
	for(auto e:g[x]){
		if(vis2[e]==false) rec(e,p);
		else if(e==p) dis2[x]=1;
		dis2[x]=min(dis2[x],dis2[e]+1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){	
		int n,m,k,s;
		long long int mn=1e9,id=1e9;	
		cin >> n >> m >> k >> s;		
		for(int i=1;i<=m;i++){
			int a,b;
			cin >> a >> b;
			g[a].push_back(b);
		}
		vis[s]=true;
		q.push({dis[s],s});
		while(!q.empty()){
			int l=q.front().first;
			int x=q.front().second;
			q.pop();
			for(auto e:g[x]){
				if(vis[e]) continue;
				vis[e]=true;
				dis[e]=dis[x]+1;
				q.push({dis[e],e});
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis2[j]=1e9;
				vis2[j]=false;
			}
			rec(i,i);
			if(!vis[i]) continue;
			if(mn>1ll*(k-1)*(dis2[i])+dis[i]){
				mn=(k-1)*(dis2[i])+dis[i];
				id=i;				
			}		
//			cout << i << ' ' << dis2[i] << ' ' << dis[i] << "\n";			
		}
		if(mn>=1e9 || id==1e9) cout << "-1\n";
		else cout << mn << ' ' << id << "\n";
		for(int i=1;i<=n;i++){
//			cout << dis[i] << ' ';
			g[i].clear();
			dis[i]=0;
			vis[i]=false;
		}
	}
}
/*
1
6 9 2 1
1 2
2 4
4 6
4 8
6 10
10 1
1 3
3 5
5 1

1
5 6 4 1
1 2
2 4
4 1
1 3
3 5
5 1


1
3 3 2 1
1 2
2 3
1 3

				if(dis[e]!=0 && vis[x]==true){

				}
				else{
					dis[e]=dis[x]+1;
					q.push({dis[e],e});
				}
*/
