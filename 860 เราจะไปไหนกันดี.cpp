#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,char>;
const int N=155,M=2505,MOD=1e9+7;
int st,p,n,m;
string s,r;
long long int dp[M][N],ans=0;
vector<pii> g[N];

inline int rec(int x,int cnt){
//	cout << x << ' ' << cnt << "\n";
	if(p==cnt){
		return 1;
	}
	if(dp[cnt][x]!=-1) return dp[cnt][x];
	long long int sum=0;
	for(auto e:g[x]){
		int xx=e.first;
		char c=e.second;	
		if(s[cnt]==c){
//			r+=c;
			sum+=rec(xx,cnt+1);
//			r.pop_back();
		}
		
	}
	return dp[cnt][x]=sum%MOD;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int a,b;
		char c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
	}
	cin >> st >> p >> s;
	memset(dp,-1,sizeof dp);
	rec(st,0);
	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout << dp[i][j] << ' ';
//		}
//		cout << "\n";
		if(dp[1][i]!=-1) ans+=dp[1][i],ans%=MOD;
	}
	cout << ans;
}
