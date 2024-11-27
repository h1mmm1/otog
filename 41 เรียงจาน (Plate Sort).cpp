#include<bits/stdc++.h>
using namespace std;
int a[300005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		int m;
		cin >> m;
		for(int i=1;i<=m;i++){
			cin >> a[i];
		}
		int cnt=m;
		for(int i=cnt;i>0;i--){
			if(a[i]==cnt) cnt--;
		}
		cout << cnt << "\n";
	}
}
