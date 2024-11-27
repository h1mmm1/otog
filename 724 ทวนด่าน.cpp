#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=2e5+5;
vector<int> g[N],G[N];
bitset<N> chk;
int n,m,k;
bool vis1[N],vis2[N],it1[N],it2[N];
vector<pii> p;

inline void rec1(int x){
	vis1[x]=true;
	it1[x]=true;
	for(auto e:g[x]){
		if(vis1[e]) continue;
		if(chk[e]==true){
			it1[e]=true;
			continue;
		}
		rec1(e);
	}
}

inline void rec2(int x){
	vis2[x]=true;
	it2[x]=true;
	for(auto e:G[x]){
		if(vis2[e]) continue;
		if(chk[e]==true){
			it2[e]=true;
			continue;
		}
		rec2(e);
	}	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);	
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a>> b;
		g[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1;i<=k;i++){
		int a,b;
		cin >> a >> b;
		if(a==1){
			chk[b]=true;
		}
		p.push_back({a,b});
	}
	rec1(1);
	rec2(n);
	stack<bool> ans;
	for(int i=p.size()-1;i>=0;i--){
		int a=p[i].first;
		int b=p[i].second;
		if(a==1){
			chk[b]=false;
			if(it1[b]) rec1(b);
			if(it2[b]) rec2(b);
		}
		else{
			ans.push(vis1[b]&vis2[b]);
		}
//		cout << a << ' ' << b << "\n";
	}
	while(!ans.empty()){
		cout << ans.top() << "\n";
		ans.pop();
	}
//	for(auto e:g[2]) cout << e << " ";
}

