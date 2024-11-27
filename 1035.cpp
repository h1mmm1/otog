#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=30,M=100005;
ll chk[M][N],a[N],sum[M][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n,m,mx=LLONG_MIN,r;
  string s;
  cin >> n >> s >> m;
  for(int i=1;i<=m;i++){
    char c;
    int x;
    cin >> c >> x;
    int t=c-'A';
    a[t]=x;
  }
  cin >> r;
  for(int i=1;i<=n;i++){
    for(int j=0;j<26;j++){
      sum[i][j]=sum[i-1][j];
      chk[i][j]=chk[i-1][j];
    }
    int t=s[i-1]-'A';
    sum[i][t]+=a[t];
    chk[i][t]++;
  }
  
  for(int i=r;i<=n;i++){
    ll x=-1,cnt=0;
    bool ok=false;
    for(int j=0;j<26;j++){
      if(chk[i][j]-chk[i-r][j]==0) continue;
      if(x<chk[i][j]-chk[i-r][j]) x=chk[i][j]-chk[i-r][j],ok=false;
      else if(x==chk[i][j]-chk[i-r][j]) ok=true;
    }
    if(ok==true || (r==1 && m!=1)){
      for(int j=0;j<26;j++){
        cnt+=sum[i][j]-sum[i-r][j];
      }
      
    }
    else{
      for(int j=0;j<26;j++){
        if(x!=chk[i][j]-chk[i-r][j]){
          cnt+=sum[i][j]-sum[i-r][j];
        }
      }
    }
    mx=max(mx,cnt);
  }
  cout << mx;
}


