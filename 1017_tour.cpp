#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<ll,ll>;
using ppi=pair<int,pii>;
const int N=2e5+1;
vector<ppi> g[N];
queue<ppi> q;
vector<pair<int,int>> p;
set<pii> s;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,l,u,v,ss,w,chk,lll,o,id=0;
	ll x,y,cnt1,cnt2,xx,yy,mn=1e18;
	scanf("%d%d%d",&n,&m,&l);
//	cin >> n >> m >> l;
	while(l--){
		scanf("%d",&o);
//		cin >> x;
	}
	while(m--){
		scanf("%d%d%d%d",&u,&v,&ss,&w);
//		cin >> u >> v >> ss >> w;
		g[u].push_back({v,{ss,w}});
	}
	q.push({1,{0,0}});
	while(!q.empty()){
		x=q.front().first;
		cnt1=q.front().second.first;
		cnt2=q.front().second.second;
		q.pop();
		if(x==n){
			p.push_back({cnt1,cnt2});
			continue;
		}
		for(auto e:g[x]){
			xx=e.first;
			chk=e.second.first;
			lll=e.second.second;
			if(chk==1) q.push({xx,{cnt1+lll,cnt2}});
			else q.push({xx,{cnt1,cnt2+lll}});
		}
	}
	sort(p.begin(),p.end());
	x=p.size();
	p.resize(unique(p.begin(),p.end())-p.begin());
	if(p.size()!=x){
		printf("0");
		return 0;
	}
	for(auto e:p){
		x=e.first;
		y=e.second;
		while(x-p[id].first>=sqrt(mn)) s.erase({p[id].second,p[id].first}),id++;
		auto sum1=s.lower_bound({y-mn,x});
		auto sum2=s.lower_bound({y+mn,x});
		for( ;sum1!=sum2;sum1++){
			xx=x-(sum1->second);
			yy=y-(sum1->first);
			mn=min(mn,xx*xx+yy*yy);
		}
		s.insert({y,x});
	}
	printf("%lld",mn);
//	cout << mn;
}
