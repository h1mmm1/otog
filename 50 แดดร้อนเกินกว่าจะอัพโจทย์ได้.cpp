#include<bits/stdc++.h>
using namespace std;
using ppi=pair<int,int>;
using pii=pair<int,ppi>;
const int N=1005;
int a[N][N];
priority_queue<pii,vector<pii>,greater<pii>> q;
bool vis[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,st1,st2,tp1,tp2;
	cin >> n;
	bool chk=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			if(a[i][j]==0){
				if(chk){
					st1=i,st2=j;
					chk=false;
				}
				else{
					tp1=i,tp2=j;
				}
			}
		}
	}
	int mn=1e9,mx=0;
	q.push({0,{st1,st2}});
	while(!q.empty()){
		int x=q.top().second.first;
		int y=q.top().second.second;
		int cnt=q.top().first;
		q.pop();
//		cout << x << ' ' << y << ' ' << cnt << "\n";
		if(vis[x][y]) continue;
		vis[x][y]=true;
		if(a[x][y]!=0) cnt=max(cnt,a[x][y]);
		if(x==tp1 && y==tp2){
			mn=min(mn,cnt);
		}
//		cout << mn << "\n";
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1 || yy<1 || xx>n || yy>n) continue;
//			cout << xx << ' ' << yy << "\n";
			if(vis[xx][yy]==false){
				q.push({cnt,{xx,yy}});
			}
		}
	}
	cout << mn;
}
