#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll a[59];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		memset(a,0,sizeof a);
		a[1]=69;
		int m;
		cin >> m;	
		for(int i=2;i<=m;i++){
			if(i%2==0) a[i]=a[i-1]+i;
			else a[i]=a[i-1]+a[i-2]+i;
		}
		cout << a[m] << "\n";
			

	}
}
