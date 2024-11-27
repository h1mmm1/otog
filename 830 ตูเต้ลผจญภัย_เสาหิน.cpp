#include<bits/stdc++.h>
using namespace std;
string a[100005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]) cnt++;
	}
	cout << cnt << "\n";
	string sub;
	for(int i=1;i<=n;i++){
		if(sub!=a[i].substr(0,3)){
			sub = a[i].substr(0,3);
			cout << a[i] << " ";
		}
	}
}
