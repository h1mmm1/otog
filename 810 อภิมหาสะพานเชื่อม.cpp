#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ppi=pair<pii,pii>;
const int N=1e5+1;
int pa[N];
vector<pii> ans2;
vector<ppi> p,pp;
vector<int> ans;
priority_queue<pii,vector<pii>,greater<pii>> q;

inline int find(int v){
	if(pa[v]==v) return v;
	return pa[v]=find(pa[v]);
}

inline void U(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		pa[a]=b;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	long long int sum=0;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		p.push_back({{c,i},{a,b}});
	}
	for(int i=1;i<=k;i++){
		int a,c;
		cin >> a >> c;
		p.push_back({{c,-i},{a,0}});
	}
	sort(p.begin(),p.end());
	for(int i=0;i<=n;i++) pa[i]=i;
	int x=0;
	for(auto e:p){
		if(x==n-1) break;
		int c=e.first.first;
		int cnt=e.first.second;
		int a=e.second.first;
		int b=e.second.second;
		if(cnt<=-1){
			sum+=c;
			ans2.push_back({-cnt,a});
			x++;
			continue;
		}
		if(find(a)!=find(b)){
			U(a,b);
			sum+=c;
			x++;
			ans.push_back(cnt);
		}
	}
	cout << sum << "\n" << ans.size() << "\n";
	for(auto e:ans){
		cout << e << "\n";
	}
	cout << ans2.size() << "\n";
	int pos=1;
	for(auto e:ans2){
		int x=find(e.second);
		while(pos<=n){
			if(x!=find(pos)){
				U(x,find(pos));
				cout << e.first << ' ' << pos << '\n';
				break;
			}
			pos++;
		}
	}
}
