#include<bits/stdc++.h>
using namespace std;
int mp[3005];
vector<int> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int m;
		cin >> m;
		mp[m]=i;
	}
	for(int i=1;i<=n;i++){
		int m;
		cin >> m;
		auto v=lower_bound(p.begin(),p.end(),mp[m])-p.begin();
		if(v==p.size()) p.push_back(mp[m]);
		else p[v]=mp[m];
	}
	cout << p.size();
}
