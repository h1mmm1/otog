#include<bits/stdc++.h>
using namespace std;
vector<int> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,ans=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		int m;
		cin >> m;
		p.push_back(m);
	}
	sort(p.begin(),p.end());
	for(int i=0;i<n;i++){
		if(p[i]!=p[i+1]) ans++;;
	}
	cout << ans;
}
