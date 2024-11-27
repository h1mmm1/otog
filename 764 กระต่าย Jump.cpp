#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e6+5;
ll vis[N];
int a[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n,m,k,cnt=1;
  cin >> n >> m >> k;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int j=1; ;j++){
    if(vis[k]!=0){ 

      int e=cnt-vis[k];
      m%=e;
      for(int i=1;i<=m;i++){
        k+=a[k];
      }
      cout << k;
      return 0;
    }
    vis[k]=cnt;
    cnt++;
    if(m==0){
      cout << k;
      return 0;
    }
    k+=a[k];
    
    m--;
//    cout << k << '\n';
  }
}
/*

7 8 5
1 2 2 3 -3 -5 -1

5 2 4 7 6 1 2 4 7 6 1 2 4
*/

