#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int a[N],mx=0;
vector<pair<pair<int,int>,int>> p;
vector<int> ans;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int l,r;
		cin >> l >> r;
		p.push_back({{r,-l},i});
	}
	sort(p.begin(),p.end());
	for(auto e:p){
		int r=e.first.first;
		int l=e.first.second;
		int id=e.second;
		auto v=upper_bound(ans.begin(),ans.end(),l)-ans.begin();
		if(v==ans.size()) ans.push_back(l);
		else ans[v]=l;
		a[id]=v+1;
		mx=max(mx,a[id]);
	}
	cout << mx << "\n";
	for(int i=1;i<=n;i++){
		cout << a[i] << ' ';
	}
}
