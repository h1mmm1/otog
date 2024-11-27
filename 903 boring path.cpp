#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<int,int>;
const int N=1e5+5;
int a[N],V[N],U[N],W[N];
vector<pii> g[N];
int x;

inline int rec(int u,int p){
	int mx=a[u];
	for(auto e:g[u]){
		int v=e.first;
		int w=e.second;
		if(w<=x && v!=p){
			mx=max(mx,rec(v,u));
		}
	}
	return mx;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n-1;i++){
		cin >> U[i] >> V[i] >> W[i];
		g[U[i]].push_back({V[i],W[i]});
		g[V[i]].push_back({U[i],W[i]});
	}
	for(int i=1;i<=n-1;i++){
		x=W[i];
		cout << 1ll*rec(V[i],U[i])*rec(U[i],V[i]) << "\n";
	}
}

