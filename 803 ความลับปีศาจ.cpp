#include<bits/stdc++.h>
using namespace std;
char a[205][205];
int dp[1505][205][205];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,t,mod=1e7+9;
	cin >> n >> m >> t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	dp[0][1][0]=1;
	for(int k=0;k<=t;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='#') continue;
				if(a[i][j]=='.'){
    		      dp[k][i][j]+=dp[k][i-1][j]+dp[k][i][j-1];
        		  dp[k][i][j]%=mod;
        } 
				if(a[i][j]=='X'){
					dp[k+1][i][j]+=dp[k][i-1][j]+dp[k][i][j-1];
        		 	dp[k+1][i][j]%=mod;
					//cout << "_";
					//dp[k][i][j]=0;
				} 
			}
		}
	}
	int sum=0;
	for(int i=0;i<=t;i++){
		sum+=dp[i][n][m];
		sum%=mod;
	}
	cout << sum;
	/*
	for(int k=0;k<=t;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout << dp[k][i][j] << ' ';
			}
			cout << "\n";
		}
		cout << "\n";		
	}
*/
}
