#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m1=0;
	cin >> n;
	while(m1!=n){
		m1++;		
		int x=1,m=m1;
		while(m%2==0){
			x++;
			m/=2;
		}
		cout << m1 << ": ";
		for(int i=1;i<=x;i++){
			cout << '*';
		}
		cout << "\n";

	}
}
