#include<bits/stdc++.h>
using namespace std;
queue<int> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ' ';
		q.pop();		
	}
}
