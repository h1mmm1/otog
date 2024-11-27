#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		bool chk=false;
		cin >> n >> m;
		memset(a,-1,sizeof a);
		for(int i=1;i<=m;i++){
			int v,u;
			cin >> v >> u;
			if(a[v]==-1) a[v]=1;
			if(a[v]!=a[u]){
				a[u]=(a[v]+1)%2;
			}
			else if(a[v]!=-1 && a[u]!=-1){
				chk=true;			
			}
		}
		if(chk) cout << "Gay found!\n";
		else cout << "Gay not found!\n";
	}
}
/*
2
3 3
0 1
1 2
0 2
4 2
0 1
2 3
*/
