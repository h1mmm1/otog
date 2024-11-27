#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=2e5+5;
int a[N];

void update(int i,int x){
	for(;i<N;i+=(i&(-i))){
		a[i]+=x;
	}
}

ll qry(int i){
	ll cnt=0;
	for(;i>=1;i-=(i&(-i))){
		cnt+=a[i];
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int x;
		cin >> x;
		if(x==1){
			int b,c,d;
			cin >> b >> c >> d;
			update(b,d);
			update(c+1,-d);
		}
		else{
			int e;
			cin >> e;
			cout << qry(e) << "\n";
		}
	}
}
