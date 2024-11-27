#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using ppi=pair<int,int>;
using pii=pair<ll,ppi>;
const int N=10;
priority_queue<pii> q;
bool vis[N][N];
char a[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	q.push({3,{1,1}});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();
		if(vis[x][y]==true || l<=0) continue;
		vis[x][y]=true;
		if(a[x][y]=='E'){
			cout << l;
			return 0;
		}
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(vis[xx][yy] || xx<1 || yy<1 || xx>n || yy>m) continue;
			if(a[xx][yy]=='*') q.push({l+1,{xx,yy}});
			else if(a[xx][yy]=='X') q.push({l-1,{xx,yy}});
			else if(a[xx][yy]=='E') q.push({l,{xx,yy}});
			
		}
	}
}
