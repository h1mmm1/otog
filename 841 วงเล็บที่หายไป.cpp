#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=505,MOD=1e9+7;
long long int dp[N][N],n;
string s;

inline int chk(char a,char b){
	int sum=0;
	if((a=='(' || a=='?') && (b==')' || b=='?')) sum++;
	if((a=='[' || a=='?') && (b==']' || b=='?')) sum++;
	return sum;
}

inline ll rec(int l,int r){
	if(l>=r) return 1;
	if(dp[l][r]!=-1) return dp[l][r];
	long long int cnt=0;
	for(int i=l+1;i<=r;i+=2){
		cnt+=(chk(s[l],s[i])*rec(l+1,i)*rec(i+1,r))%MOD;
	}
	return dp[l][r]=cnt%MOD;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	memset(dp,-1,sizeof dp);
	cout << rec(0,n-1)%MOD;
}
