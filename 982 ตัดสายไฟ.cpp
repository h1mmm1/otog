#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<ll,ll>;
using ppi=pair<ll,pii>;
const int N=1e5+5;
vector<ppi> p;
vector<pii> g[N];
int pa[N];
ll dp[N],ans1=0,ans2=0,ans=0,mn=1e18;

inline void rec(int x,int v){
  for(auto e:g[x]){
    if(e.first==v) continue;
    rec(e.first,x);    
    dp[x]+=dp[e.first]+e.second;
  }
  
  for(auto e:g[x]){
  	if(e.first==v) continue;
    ll cnt=ans-dp[e.first]-e.second;
    ll sum=dp[e.first];
    if(sum==0 || cnt==0) continue;
    if(mn>abs(cnt-sum)){
//    	cout << x << ' ' << e.first << ' ' << cnt <<  ' ' << sum << '\n';
      ans1=min(sum,cnt);
      ans2=max(cnt,sum);  
      mn=abs(cnt-sum);
    }
  }
}

int find(int a){
  if(pa[a]==a) return a;
  return pa[a]=find(pa[a]);
}

void U(int a,int b){
  a=find(a);
  b=find(b);
  if(a!=b){
    pa[a]=b;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<=n;i++) pa[i]=i;
  for(int i=1;i<=m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    p.push_back({c,{a,b}});
  }	
  sort(p.begin(),p.end());
  for(auto e:p){
    int c=e.first;
    int a=e.second.first;
    int b=e.second.second;
    if(find(a)==find(b)) continue;
    U(a,b);
    ans+=c;
    g[a].push_back({b,c});
	g[b].push_back({a,c});
  }
  rec(0,-1);
//	cout << st << "\n";
//	for(int i=0;i<n;i++) cout << dp[i] << ' ';
  cout << ans << "\n" << ans1 << ' ' << ans2;
}
/*
4 4
0 3 20
0 1 5
1 3 10
0 2 4

5 7
4 3 2
3 0 6
3 1 8
1 2 3
4 1 5
4 2 7
3 4 9


4 3
0 1 10
1 2 1
2 3 1
*/

