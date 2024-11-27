#include<bits/stdc++.h>
using namespace std;
vector<int> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	if(n<10 && n!=0){
		cout << n;
		return 0;
	}
	if(n==0){
		cout << "-1";
		return 0;
	}
	while(n%9==0){
		p.push_back(9);
		n/=9;
	}
	while(n%8==0){
		p.push_back(8);
		n/=8;
	}
	while(n%7==0){
		p.push_back(7);
		n/=7;
	}
	while(n%6==0){
		p.push_back(6);
		n/=6;
	}
	while(n%5==0){
		p.push_back(5);
		n/=5;
	}
	while(n%4==0){
		p.push_back(4);
		n/=4;
	}
	while(n%3==0){
		p.push_back(3);
		n/=3;
	}
	while(n%2==0){
		p.push_back(2);
		n/=2;
	}		
	sort(p.begin(),p.end());						
	if(p.size()==0 || p.size()==1) cout << "-1";
	else {
		for(auto e:p) cout << e;
	}
	
}
