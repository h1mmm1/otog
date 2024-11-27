#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,cnt=0,ans=0,mx=1;
	cin >> n;
	while(n>0){
		m=n%3;
		n/=3;
		if(m==1){
			cnt++;
			ans+=mx;
		}
		else if(m==2){
			n++;
			cnt++;
		}
		mx*=3;
//		cout << cnt << ' ' << ans << "\n";
	}
	cout << cnt << ' ' << ans;
}
