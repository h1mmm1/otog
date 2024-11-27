#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int a[10005];
ll x[10005];
ll ix[10005];

ll mod(ll n,ll m,ll x){
  ll ans=1;
  while(m>0){
    if(m%2==1){
      ans*=n;
      ans%=x;
    }
    n*=n;
    n%=x;
    m/=2;
  }
  return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  ix[0]=1;
  x[0]=1;
  int y=1000000007;
	int n,m;
  ll sum=0,dii=1;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  sort(a+1,a+1+n);
  for(int i=1;i<=10005;i++){
    x[i]=(i*x[i-1])%y;
    ix[i]=mod(x[i],y-2,y);
  }
  for(int i=m;i<=n;i++){
    dii=x[i-1]*ix[m-1];
    dii%=y;
    dii*=a[i];
    dii%=y;
    dii*=ix[i-m];
    dii%=y;
    sum+=dii;
    sum%=y;
  }
  cout << sum;
}
/*
i=1 2 3 4 5 6  m=4 
  0 1 2 3 5 8

  a[i]*(5!/3!/2!)

  */
