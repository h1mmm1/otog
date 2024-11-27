#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=1e6+5;
priority_queue<pii,vector<pii>,greater<pii>> q;
priority_queue<int> p;
vector<pii> g[N];
int dis[N];
bool vis[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i=0;i<=n;i++) dis[i]=1e6;
	dis[0]=0;
	q.push({dis[0],0});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		p.push(dis[x]);
		for(auto e:g[x]){
			int xx=e.first;
			int ll=e.second;
			if(dis[xx]>ll && vis[xx]==false){
				dis[xx]=ll;
				q.push({dis[xx],xx});
			}
		}
	}
	long long int ans=0;
	
	for(int i=1;i<=k;i++){
		int x=p.top();
		x/=2;
		p.pop();
		p.push(x);
	}

//	for(auto e:p) cout << e << ' ';	
	for(int i=1;i<=n;i++){
		ans+=p.top();
//		cout << p.top() << ' ';
		p.pop();
	}
	printf("%d",ans);
}
