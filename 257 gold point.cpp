#include<bits/stdc++.h>
using namespace std;
const int N=2501;
char a[N][N];
int dis[N][N];
//bool vis[N][N];
queue<pair<int,pair<int,int>>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
//	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			scanf("%c",&a[i][j]);
			cin >> a[i][j];
			dis[i][j]=1000000000;
			if(a[i][j]=='K') q.push({2,{i,j}}),dis[i][j]=-1;
		}
	}
	int mx=0,cnt=0;	
	while(!q.empty()){
		int t=q.front().first;
		int x=q.front().second.first;
		int y=q.front().second.second;
		q.pop();
		if(mx<dis[x][y]){
			mx=dis[x][y];
			cnt=0;
		}
		if(mx==dis[x][y]) cnt++;
//		if(vis[x][y]) continue;
//		vis[x][y]=true;
//		cout << x << ' ' << y << "\n";
		if(t==1 || t==2){
			for(int i=y+1;i<=n;i++){
				if(a[x][i]=='#') break;
				if(dis[x][i]>dis[x][y]+1){
					q.push({0,{x,i}});
					dis[x][i]=dis[x][y]+1;
				}
			}
			for(int i=y-1;i>=1;i--){
				if(a[x][i]=='#') break;
				if(dis[x][i]>dis[x][y]+1){
					q.push({0,{x,i}});
					dis[x][i]=dis[x][y]+1;				
				}
			}			
		}
		if(t==0 || t==2){
			for(int i=x+1;i<=n;i++){
				if(a[i][y]=='#') break;
				if(dis[i][y]>dis[x][y]+1){
					q.push({1,{i,y}});
					dis[i][y]=dis[x][y]+1;
				}
			}
			for(int i=x-1;i>=1;i--){
				if(a[i][y]=='#') break;
				if(dis[i][y]>dis[x][y]+1){
					q.push({1,{i,y}});
					dis[i][y]=dis[x][y]+1;				
				}
			}			
		}
		
	}
	printf("%d\n%d",mx,cnt);
//	cout << mx << '\n' << cnt;
}
