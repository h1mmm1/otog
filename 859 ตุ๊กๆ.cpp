#include<bits/stdc++.h>
using namespace std;
using ppi=pair<int,int>;
using pii=pair<int,ppi>;
vector<pii> p;
const int N=1e5+5;
int pa[N];
priority_queue<int,vector<int>,greater<int>> q;
set<int> s;

int find(int v){
	if(pa[v]==v) return v;
	return pa[v]=find(pa[v]);
}

void U(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		pa[a]=b;
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		p.push_back({c,{a,b}});
	}
	sort(p.begin(),p.end(),greater<pii>());
	for(auto e:p){
		int c=e.first;
		int a=e.second.first;
		int b=e.second.second;
		if(find(a)!=find(b)){
			U(a,b);
			q.push(c);
			cout << c << ' ';
		}
	}
	for(int i=1;i<=n;i++) s.insert(find(i));
	k-=s.size();
//	cout << s.size() << "\n";
	while(!q.empty() && k--) q.pop();
	if(q.empty()) cout << "0";
	else cout << q.top(); 
}
/*
7 5 4
1 2 32
4 3 30
4 5 24
3 5 12
3 6 20

12
15
8
1 3 25
3 2 12
1 2 40
4 5 26
7 4 18
7 6 32
4 6 31
8 9 20
9 10 17
9 12 29
8 11 42
10 11 56
10 8 31
12 10 11
11 12 45
*/
