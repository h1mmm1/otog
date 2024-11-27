#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n,m,mx=1;
char a[N][N];
bool vis[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


void rec(int x,int y,int cnt){
	if(a[x][y]=='E'){
		mx=max(mx,cnt);
		return;
	}
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1 || yy<1 || xx>n || yy>m || vis[xx][yy]) continue;
		vis[xx][yy]=true;
		if(a[xx][yy]=='*') rec(xx,yy,cnt+1);
		else if(a[xx][yy]=='X' && cnt>0) rec(xx,yy,cnt-1);
		else if(a[xx][yy]=='E') rec(xx,yy,cnt);
		vis[xx][yy]=false;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	rec(1,1,3);
	cout << mx;
}
