#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(a,0,sizeof a);
		int n;
		cin >> n;
		bool chk=true;
		for(int i=1;i<=n;i++){
			int x,y;
			cin >> x >> y;
			a[x]++,a[y+1]--;
		}
		for(int i=1;i<N;i++){
			a[i]+=a[i-1];
			if(a[i]==n){
				chk=false;
				break;
			}
		}
		if(chk==false) cout << "no\n";
		else cout << "yes\n";
	}
}
