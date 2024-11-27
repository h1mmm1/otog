#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> g[N];
vector<int> p;
int vis[N],n,m;

inline void rec(int x){	
	vis[x]=1;
	p.push_back(x);
	for(auto e:g[x]){
		if(vis[e]==2) continue;
		if(vis[e]==1){
			cout << "no";
			exit(0);
		}
		rec(e);
	}
	vis[x]=2;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0) rec(i);
	}
	for(auto e:p){
		cout << e << "\n";
	}
//	while(!p.empty()){
//		cout << p.top() << ' ';
//		p.pop();
//	}
}
