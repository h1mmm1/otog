#include<bits/stdc++.h>
using namespace std;
const int N=123460;
int c[N];
int r[N];
int sum[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> c[i];
  }
  for(int i=1;i<=m;i++){
    cin >> r[i];
  }
  sort(r+1,r+1+m);
  for(int i=1;i<=m;i++){
    sum[i]=sum[i-1]+r[i];  	
  }
  long long int ans=0;
  for(int i=1;i<=n;i++){
    auto v=lower_bound(r+1,r+1+m,c[i])-r;
//    cout << v << ' ';
    ans+=sum[v-1];
   ans+=c[i]*(m-v+1);
//    cout << sum[v-1] << ' ';
//    cout << c[i]*(m-v+1) << '\n';
  }
  cout << ans;
//  for(int i=1;i<=n;i++){
//  	cout << sum[i] << ' ';
//  }
}

//      10 15  19  30  50   70  90
// 24   10 15  19  24  24   24  24
// 25   10 15  19  25  25   25  25
  

//3 4
//2 4

