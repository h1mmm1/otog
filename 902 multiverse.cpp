#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
bool vis[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,ans=0;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++){
			if(vis[i]==false){
				int cnt=1;
				int v=i;
				vis[v]=true;
				v=a[v];
				while(v!=i){
					vis[v]=true;
					cnt++;
					v=a[v];
				}
				int sum=-1;
				if(cnt==1) sum=1;
				else if(cnt%2==0) sum=2;
				else sum=3;
				ans=max(ans,sum);
			}
		}
		cout << ans << '\n';
		memset(vis,false,sizeof vis);
	}
}
