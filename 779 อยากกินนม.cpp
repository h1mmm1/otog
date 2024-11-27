#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5;
priority_queue<ll,vector<ll>,greater<ll>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		q.push(x);
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		ans+=q.top();
		q.push(q.top()*105/100);
		q.pop();
	}
	cout << ans;
}
