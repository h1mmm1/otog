#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=2e6+5,P=53,MOD=1e9+7;
ll h1[N],h2[N],p[N*2];

int main(){
//	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	string s;
//	cin >> n >> m >> s;
	scanf("%d%d",&n,&m);
	scanf("% s",&s);
	p[0]=1;
	for(int i=1;i<2*N;i++){
		p[i]=p[i-1]*P;
		p[i]%=MOD;
	}
	for(int i=1;i<=n;i++){
		h1[i]=h1[i-1]+s[i-1]*p[i];
		h1[i]%=MOD;
		h2[i]=h2[i-1]+s[n-i]*p[i];
		h2[i]%=MOD;
	}
	while(m--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//		cin >> x1 >> y1 >> x2 >> y2;
		ll cnt1=h1[y1]-h1[x1-1]+MOD;cnt1%=MOD;
		ll cnt2=h1[y2]-h1[x2-1]+MOD;cnt2%=MOD;
		ll sum1=h2[n-x1+1]-h2[n-y1]+MOD;sum1%=MOD;
		ll sum2=h2[n-x2+1]-h2[n-y2]+MOD;sum2%=MOD;
		cnt1*=p[2*n-y2+x2-1-y1];cnt1%=MOD;
		cnt2*=p[2*n-y2];cnt2%=MOD;
		sum1*=p[2*n-n+x1-1];sum1%=MOD;
		sum2*=p[2*n+x1-y1-1-n+x2-1];sum2%=MOD;
		if((cnt1+cnt2)%MOD==(sum1+sum2)%MOD){
//			cout << "YES\n";
			printf("YES\n");
		}		
//		else cout << "NO\n";
		else printf("NO\n");
//		cout << (cnt1+cnt2)%MOD << ' ' << (sum2+sum1)%MOD << '\n';
	}
//	cout << h1[1];
}
/*
3 1
AAA
1 1 2 3
*/
