#include<bits/stdc++.h>
using namespace std;
int a[100005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	long long int sum=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	int cnt=n/4;
	int x=1;
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=cnt;i++){
		sum-=a[i+x];
		cout << a[i+x] << ' ';
		x+=1;
	}
	cout << sum;
}
/*
8
9
8
7
6
5
4
3
2
*/
