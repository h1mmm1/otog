#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e6+5;
vector<int> p,v;
int a[N],mp[M],id[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
//		mp[i]=i;
	}
//	memset(mp,-1,sizeof mp);
	for(int i=n;i>=1;i--){
		auto v=lower_bound(p.begin(),p.end(),a[i],greater<int>())-p.begin();
		if(v==p.size()) p.push_back(a[i]);
		else p[v]=a[i];
		if(v>=1) mp[i]=id[v-1];
		id[v]=i;
//		cout << v << ' ' << i << '\n';
	}
	cout << p.size() << "\n";
	int x=id[p.size()-1];
//	for(int i=1;i<=p.size();i++) cout << id[i] << ' ';
//	cout << "\n";
//	for(int i=1;i<=p.size();i++) cout << mp[i] << ' ';
//	cout << x << '\n';
	while(x>0){
		v.push_back(x);
//		cout << x << ' ';
		x=mp[x];
//		cout << x << "\n";
	}
	sort(v.begin(),v.end());
	for(auto e:v) cout << a[e] << ' ';
}

