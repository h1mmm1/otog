#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int n,cnt=0;
	string s;
	cin >> n >> s;
	char chk=s[0];
	if(chk=='0') cnt++;
	for(auto e:s){
		if(chk!=e) cnt++,chk=e;;
	}
	cout << cnt;
}
