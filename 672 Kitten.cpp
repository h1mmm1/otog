#include<bits/stdc++.h>
using namespace std;
const int N=15;
int b[N],a[N];
bool vis[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,sum=1;
	cin >> n >> m;
	b[0]=1;
	int id=n;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]*i;
	}
	for(int i=1;i<=n;i++){
		a[id]=b[i-1];
		id--;
	}
	while(m--){
		int cnt=1;
		for(int i=1;i<=n;i++){
			cin >> b[i];
		}
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<b[i];j++){
				if(vis[j]==false) sum++;
			}
			cnt+=sum*a[i];
			vis[b[i]]=true;
		}
		memset(vis,false,sizeof vis);
		cout << cnt << "\n";
	}
}

/*
2 2
1 2
2 1

3 6
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

4 24
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1

5 7
1 2 3 4 5
1 2 3 5 4
2 1 3 4 5
3 1 2 4 5
4 1 2 3 5
5 1 2 3 4
5 4 3 2 1
*/
