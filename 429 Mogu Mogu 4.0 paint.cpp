#include<bits/stdc++.h>
using namespace std;
const int N=505,M=55;
int a[N],dp[N][M][M],n;

int rec(int i,int x,int y){
	if(i==n+1) return 0;
	if(dp[i][x][y]!=-1) return dp[i][x][y];
	if(a[i]==x || a[i]==y) return dp[i][x][y]=rec(i+1,x,y);
	else return dp[i][x][y]=min(rec(i+1,a[i],y)+1,rec(i+1,x,a[i])+1); 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(dp,-1,sizeof dp);
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		cout << rec(1,0,0) << "\n";
	}
}
