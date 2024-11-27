#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e6+5;
int a[N],b[M],mp[M];
bool chk[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		int x;
		cin >> x;
		b[x]++;
	}
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		mp[a[i]]++;
		if(mp[a[i]]<=b[a[i]]){
			cnt++;
		}
//		cout << cnt << " ";
		if(i>=m){
			if(cnt>=k) ans++;
			if(b[a[i-m+1]]!=0){
				mp[a[i-m+1]]--;
				if(mp[a[i-m+1]]<b[a[i-m+1]]) cnt--;		
//				cout << a[i-m+1] << "\n";		
			}
		}
//		cout << ans << "\n";
	}
//	cout << '\n';
//	for(int i=1;i<=n;i++) cout << b[i] << " ";
//	cout << '\n';
	cout << ans;
}
/*
5 2 4
1 1 1 1 1
1 1 


5 2 3
1 1 1 1 1
1 1 
*/
