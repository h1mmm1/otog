#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
const int N=105;
int a[N];
vector<int> p;
queue<int> q;

void rec(int x,int sum){
	if(sum==n){
		ans++;
		q.push(p.size());
		for(auto e:p) q.push(e);
//		cout << "\n";
		return;
	}
	if(x==m || sum>n) return;
	for(int i=1;i<=6;i++){
		p.push_back(a[i]);
		rec(x+1,sum+a[i]);
		p.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=6;i++) cin >> a[i];
	rec(0,0);
	cout << ans << "\n";
	while(!q.empty()){
		cout << "E\n";
		int x=q.front();
		cout << x << ' ';
		q.pop();
		for(int i=1;i<=x;i++){
			cout << q.front() << ' ';
			q.pop();
		}	
		cout << "\n";	
	}
	cout << "E";
//	while(!q.empty()){
//		cout << q.front() << " ";
//		q.pop();
//	}
}

