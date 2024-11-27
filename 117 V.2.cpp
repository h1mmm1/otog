#include<bits/stdc++.h>
using namespace std;
const int N=100;
int dis[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dis[i][j]=1e9;
		}
	}
	for(int i=0;i<N;i++) dis[i][i]=0;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		char s,c;
		int b;
		cin >> s >> c >> b;
		int x=s-'A';
		int y=c-'A';
		if(dis[x][y]>b){
			dis[x][y]=dis[y][x]=b;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	int mx=INT_MAX;
	char id;
	for(char i='A';i<'Z';i++){
		if(dis[i-'A']['Z'-'A']<mx){
			mx=dis[i-'A']['Z'-'A'];
			id=i;
		}
	}
	cout << id << ' ' << mx;
}
