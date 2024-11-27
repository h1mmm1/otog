#include<bits/stdc++.h>
using namespace std;
using ppi=pair<int,int>;
using pii=pair<ppi,ppi>;
const int N=60;
int a[N][N],dis[N*N][N][N];
priority_queue<pii,vector<pii>,greater<pii>> q,g;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[N*N][N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,st1,st2,tp1,tp2;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			for(int k=0;k<n*n;k++){
				dis[k][i][j]=1e9;
			}
			
		}
	}
	cin >> st1 >> st2 >> tp1 >> tp2;
	dis[0][st1][st2]=0;
	q.push({{dis[0][st1][st2],0},{st1,st2}});
	while(!q.empty()){
		int l=q.top().first.first;
		int t=q.top().first.second;
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();	
		if(t%2==1 && x==tp1 && y==tp2){
			cout << l;
			return 0;
		}
//		cout << t << ' ' << x << ' ' << y << "\n";
		if(vis[t][x][y]) continue;
		vis[t][x][y]=true;
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1 || yy<1 || xx>n || yy>n) continue;
			if(a[xx][yy]<0){
				if(dis[t+1][xx][yy]>dis[t][x][y]-a[xx][yy]){
					dis[t+1][xx][yy]=dis[t][x][y]-a[xx][yy];
					q.push({{dis[t+1][xx][yy],t+1},{xx,yy}});
				}
			}
			else{
				if(dis[t][xx][yy]>dis[t][x][y]+a[xx][yy]){
					dis[t][xx][yy]=dis[t][x][y]+a[xx][yy];
					q.push({{dis[t][xx][yy],t},{xx,yy}});
				}				
			}
		}
	}
}
