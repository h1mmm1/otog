#include<bits/stdc++.h>
using namespace std;
int a[26][26],n,mn=INT_MAX;
bool vis[26];

void rec(int cnt,int sum){
	if(cnt==n){
		mn=min(mn,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==true) continue;
		int x=sum+a[cnt+1][i];
		vis[i]=true;
		rec(cnt+1,x);
		vis[i]=false;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	rec(0,0);
	cout << mn;
}
