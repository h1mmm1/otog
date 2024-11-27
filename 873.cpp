#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int qr[N];

inline void update(int i,int v){
  for(;i<N;i+=i&(-i)){
    qr[i]+=v;
  }
}

inline int query(int i){
  int cnt=0;
  for(;i>=1;i-=i&(-i)){
    cnt+=qr[i];
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    int a;
    cin >> a;
    cout << query(a) << ' ';
    update(a,1);
  }
}

