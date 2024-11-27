#include<bits/stdc++.h>
using namespace std;
int a[505][505];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s,c;
	cin >> s >> c;
	int n=s.size();
	int m=c.size();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0) a[i][j]=0;
			else if(s[i-1]==c[j-1]) a[i][j]=a[i-1][j-1]+1;
			else a[i][j]=max(a[i-1][j],a[i][j-1]);
		}
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << a[i][j] <<' ';
		}
		cout << "\n";
	}
	*/
	cout << a[n][m];
}
