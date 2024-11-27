#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],x[N],l[N],r[N];
vector<int> p,g;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		auto v=lower_bound(p.begin(),p.end(),a[i])-p.begin();
		if(v==p.size()) p.push_back(a[i]);
		else p[v]=a[i];
		l[i]=v+1;
	}
	p.clear();
	for(int i=n;i>0;i--){
		auto v=lower_bound(p.begin(),p.end(),a[i])-p.begin();		
		if(v==p.size()) p.push_back(a[i]);
		else p[v]=a[i];
		r[i]=v+1;
		g.push_back(r[i]+l[i]);
	}
	sort(g.begin(),g.end());
	sort(x+1,x+1+n);
	long long int mx=0;
	for(int i=1;i<=n;i++){
		mx+=1ll*(x[i])*(g[i-1]);
//		cout << (x[i])<< ' ' << (g[i-1]) << "\n";
	}
	cout << mx;
//	for(int i=1;i<=n;i++){
//		cout << l[i] << ' ';
//	}
//	cout << "\n";
//	for(int i=1;i<=n;i++){
//		cout << r[i] << ' ';
//	}	
}
