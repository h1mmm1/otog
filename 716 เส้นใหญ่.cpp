#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int pa[N];

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
	int n,m;
	cin >> n >>m;
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		U(a,b);
	}
	for(int i=1;i<=n;i++) cout << pa[i] << ' ';
	int q;
	cin >> q;
	while(q--){
		int a,b;
		cin >> a >> b;
		if(find(a)==find(b)) cout << "true\n";
		else cout << "false\n";
	}
}
