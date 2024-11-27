#include<bits/stdc++.h>
using namespace std;
vector<int> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string a,b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int n=a.size(),m=b.size(),i=0,ct=0;
	for(i=0;i<min(n,m);i++){
		int cnt=a[i]-'0'+b[i]-'0'+ct;
		ct=0;
		p.push_back(cnt%10);
		if(cnt>=10) ct=1;
	}
	for( ;i<n;i++){
		int cnt=a[i]-'0'+ct;
		ct=0;
		p.push_back(cnt%10);
		if(cnt>=10) ct=1;		
	}
	for( ;i<m;i++){
		int cnt=b[i]-'0'+ct;
		ct=0;
		p.push_back(cnt%10);
		if(cnt>=10) ct=1;		
	}	
	if(ct==1) p.push_back(1);
	reverse(p.begin(), p.end());
	for(auto e:p) cout << e;
}
